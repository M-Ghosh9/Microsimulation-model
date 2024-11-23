# data_loading.py

import pandas as pd
import numpy as np

def load_data(patients_file, metrics_file):
    """Loads and preprocesses datasets."""
    patients_data = pd.read_csv(patients_file)

    with open(metrics_file, "r") as f:
        population_metrics = f.read()
    metrics = {}
    for line in population_metrics.splitlines():
        if ":" in line:
            try:
                key, value = line.split(":")
                clean_value = "".join(filter(lambda x: x.isdigit() or x == ".", value))
                metrics[key.strip()] = float(clean_value) if clean_value else None
            except ValueError as e:
                print(f"Error parsing line: {line} -> {e}")
    return patients_data, metrics

def preprocess_data(df):
    """Prepares the dataset for analysis."""
    # Split RiskFactors column into multiple binary columns
    risk_factors = ['diabetes', 'hypertension', 'obesity', 'smoking']
    for factor in risk_factors:
        df[factor] = df['RiskFactors'].str.contains(factor, case=False, na=False).astype(int)

    # Add Gender column with random values
    np.random.seed(42)
    df['Gender'] = np.random.choice(['Male', 'Female'], size=len(df))

    return df

def add_extreme_cases(df):
    """Adds extreme cases to the dataset for testing."""
    extremes = pd.DataFrame({
        'ID': ['E1', 'E2'],
        'Age': [5, 95],
        'Ethnicity': ['asian', 'black'],
        'HealthScore': [5, 99],
        'RiskFactors': ['diabetes,smoking', 'hypertension,obesity'],
        'Gender': ['Male', 'Female']
    })
    extremes['diabetes'] = [1, 0]
    extremes['hypertension'] = [0, 1]
    extremes['obesity'] = [0, 1]
    extremes['smoking'] = [1, 0]

    return pd.concat([df, extremes], ignore_index=True)
