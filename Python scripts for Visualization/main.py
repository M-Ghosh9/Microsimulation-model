# main.py

# main.py

from data_loading import load_data, preprocess_data, add_extreme_cases
from analysis import (age_distribution, healthscore_distribution, gender_vs_risk_factors, 
                      ethnicity_vs_risk_factors, healthscore_by_age_gender, 
                      heatmap_risk_factors, risk_factor_proportions)
from predictive_model import train_predictive_model
from dashboard import create_dashboard

def main_analysis():
    # Load and preprocess data
    patients_file = "patients_data.csv"
    metrics_file = "population_metrics.txt"
    patients_data, metrics = load_data(patients_file, metrics_file)
    patients_data = preprocess_data(patients_data)
    patients_data = add_extreme_cases(patients_data)

    # Perform analysis
    age_distribution (patients_data)
    healthscore_distribution (patients_data)
    gender_vs_risk_factors (patients_data)
    ethnicity_vs_risk_factors (patients_data)
    healthscore_by_age_gender (patients_data)
    heatmap_risk_factors (patients_data)
    risk_factor_proportions (patients_data)

    # Train predictive model
    model = train_predictive_model(patients_data)
    
    # Debugging data distribution for true labels
    print("Risk factor distribution:")
    print(patients_data[['diabetes', 'hypertension', 'obesity', 'smoking']].sum())

    return patients_data, metrics

if __name__ == "__main__":
    # Run analysis and dashboard only if script is executed directly
    patients_data, metrics = main_analysis()
    create_dashboard(patients_data, metrics)
