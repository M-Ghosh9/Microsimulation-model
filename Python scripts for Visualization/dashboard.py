#dashboard.py

from dash import Dash, html, dcc, Input, Output
import pandas as pd
import plotly.express as px
import plotly.graph_objects as go
import numpy as np
import os

app = Dash(__name__)

# Ensure outputs directory exists
if not os.path.exists("outputs"):
    os.makedirs("outputs")

# Add noise to data for variation
def add_noise(df, noise_factor=0.05):
    """Add random noise to data for more realistic visualizations."""
    df['HealthScore'] += np.random.normal(0, noise_factor * df['HealthScore'].std(), len(df))
    for col in ['diabetes', 'hypertension', 'obesity', 'smoking']:
        df[col] += np.random.normal(0, noise_factor, len(df))
        df[col] = df[col].clip(0, 1)  # Ensure values stay between 0 and 1
    return df

def create_dashboard(df, metrics):
    """Creates and launches the interactive healthcare dashboard."""
    # Add age bins and noise
    df['AgeGroup'] = pd.cut(df['Age'], bins=[0, 20, 40, 60, 80, 100], labels=['0-20', '21-40', '41-60', '61-80', '81+'])
    df = add_noise(df)

    # Calculate population metrics for overview
    total_males = (df["Gender"] == "Male").sum()
    total_females = (df["Gender"] == "Female").sum()
    total_conditions = {
        "Diabetes": df["diabetes"].sum(),
        "Smoking": df["smoking"].sum(),
        "Hypertension": df["hypertension"].sum(),
        "Obesity": df["obesity"].sum(),
    }

    # App layout
    app.layout = html.Div([
        html.H1("Healthcare Dashboard"),

        # Top-level pie charts
        html.Div([
            html.H3("Population Overview"),
            html.Div([
                dcc.Graph(
                    id="gender-pie-chart",
                    figure=px.pie(
                        names=["Males", "Females"],
                        values=[total_males, total_females],
                        title="Gender Distribution"
                    )
                ),
                dcc.Graph(
                    id="conditions-pie-chart",
                    figure=px.pie(
                        names=list(total_conditions.keys()),
                        values=list(total_conditions.values()),
                        title="Total People with Conditions"
                    )
                )
            ], style={"display": "flex", "justifyContent": "space-around"}),
        ], style={"marginBottom": "30px"}),

        # Dropdown to select factors
        html.Div([
            html.Label("Select Factor(s) to Visualize:"),
            dcc.Dropdown(
                id="factor-selector",
                options=[
                    {"label": "Age", "value": "Age"},
                    {"label": "Gender", "value": "Gender"},
                    {"label": "Ethnicity", "value": "Ethnicity"},
                    {"label": "HealthScore", "value": "HealthScore"},
                    {"label": "Diabetes", "value": "diabetes"},
                    {"label": "Hypertension", "value": "hypertension"},
                    {"label": "Obesity", "value": "obesity"},
                    {"label": "Smoking", "value": "smoking"}
                ],
                multi=True,
                placeholder="Select one or more factors"
            ),
        ], style={"marginBottom": "20px"}),

        # Slider to modify thresholds dynamically
        html.Div([
            html.Label("Adjust Threshold for Risk Factors (%):"),
            dcc.Slider(id="threshold-slider", min=0, max=100, step=1, value=50),
        ], style={"marginBottom": "20px"}),

        # Graph display and descriptions
        dcc.Graph(id="dynamic-plot"),
        html.Div(id="plot-description", style={"marginTop": "10px"}),

        # Suggestions
        html.Div(id="dynamic-suggestions", style={"marginTop": "20px", "border": "1px solid #ccc", "padding": "10px"}),

        # Generate Report Button
        html.Button("Generate Report", id="generate-report-button", style={"marginTop": "20px"}),
        html.Div(id="download-link", style={"marginTop": "10px"})
    ])

    # Callback to generate plots dynamically
    @app.callback(
        [Output("dynamic-plot", "figure"), Output("plot-description", "children"), Output("dynamic-suggestions", "children")],
        [Input("factor-selector", "value"), Input("threshold-slider", "value")]
    )
    def update_plots(selected_factors, threshold_value):
        """Dynamically generate plots based on selected factors and thresholds."""
        # Validate input
        if not selected_factors:
            return go.Figure(), "Please select at least one factor to visualize.", "No data points available."

        filtered_df = df.copy()

        # Apply threshold filter to risk factors
        for factor in ['diabetes', 'hypertension', 'obesity', 'smoking']:
            if factor in selected_factors:
                filtered_df = filtered_df[filtered_df[factor] * 100 > threshold_value]

        # Determine plot type based on number of selected factors
        if len(selected_factors) == 1:
            # Single factor: Histogram or pie chart
            factor = selected_factors[0]
            if factor in ['Gender', 'Ethnicity']:
                figure = px.pie(filtered_df, names=factor, title=f"Distribution of {factor}")
                description = f"The pie chart shows the distribution of {factor} in the dataset."
            else:
                figure = px.histogram(filtered_df, x=factor, nbins=20, title=f"Distribution of {factor}")
                description = f"The histogram shows the frequency distribution of {factor}."
        elif len(selected_factors) == 2:
            # Two factors: Grouped bar chart or scatter plot
            factor_x, factor_y = selected_factors
            if "Gender" in selected_factors:
                figure = px.bar(
                    filtered_df, x=factor_x, y=factor_y, color="Gender",
                    title=f"{factor_x} vs {factor_y} by Gender",
                    color_discrete_map={"Male": "blue", "Female": "red"}
                )
                description = f"The bar chart compares {factor_x} and {factor_y}, grouped by gender."
            else:
                figure = px.scatter(filtered_df, x=factor_x, y=factor_y, title=f"{factor_x} vs {factor_y}")
                description = f"The scatter plot shows the relationship between {factor_x} and {factor_y}."
        elif len(selected_factors) == 3:
            # Three factors: 3D scatter plot
            factor_x, factor_y, factor_color = selected_factors
            figure = px.scatter_3d(
                filtered_df, x=factor_x, y=factor_y, z=factor_color, color="Gender",
                title=f"{factor_x} vs {factor_y} vs {factor_color} by Gender",
                color_discrete_map={"Male": "blue", "Female": "red"}
            )
            description = f"The 3D scatter plot visualizes {factor_x}, {factor_y}, and {factor_color} grouped by gender."
        else:
            # Multivariate: Parallel coordinates
            figure = px.parallel_coordinates(
                filtered_df, dimensions=selected_factors,
                title="Multivariate Analysis"
            )
            description = "The parallel coordinates plot visualizes relationships among multiple factors."

        # Generate dynamic suggestions
        if filtered_df.empty:
            suggestion = "No data points match the current filters and thresholds."
        else:
            suggestion = f"{len(filtered_df)} records match your selection. Consider targeted actions for these subsets."

        return figure, description, suggestion

    # Callback to generate report
    @app.callback(
        Output("download-link", "children"),
        [Input("generate-report-button", "n_clicks")]
    )
    def generate_report(n_clicks):
        """Generates a comprehensive HTML report."""
        if not n_clicks:
            return ""

        # Generate report content
        report_path = "outputs/healthcare_report.html"
        with open(report_path, "w") as f:
            f.write("<html><head><title>Healthcare Report</title></head><body>")
            f.write("<h1>Healthcare Report</h1>")
            f.write("<h2>Metrics Overview</h2>")
            f.write(f"<p>Total Males: {total_males}</p>")
            f.write(f"<p>Total Females: {total_females}</p>")
            for condition, count in total_conditions.items():
                f.write(f"<p>Total {condition}: {count}</p>")
            f.write("<h2>Decision Log</h2>")
            for log in decision_log:
                f.write(f"<p>{log}</p>")
            f.write("</body></html>")

        return html.A("Download Report", href=report_path, target="_blank")

    app.run_server(debug=False)
