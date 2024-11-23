# analysis.py

import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns


def age_distribution(df):
    """Plot the distribution of ages."""
    plt.figure(figsize=(10, 6))
    sns.histplot(df['Age'], bins=20, kde=True, color="blue")
    plt.title("Age Distribution")
    plt.xlabel("Age")
    plt.ylabel("Count")
    plt.show()


def healthscore_distribution(df):
    """Plot the distribution of health scores."""
    plt.figure(figsize=(10, 6))
    sns.histplot(df['HealthScore'], bins=20, kde=True, color="green")
    plt.title("HealthScore Distribution")
    plt.xlabel("HealthScore")
    plt.ylabel("Count")
    plt.show()


def gender_vs_risk_factors(df):
    """Compare risk factors between genders."""
    risk_factors = ['diabetes', 'hypertension', 'obesity', 'smoking']
    gender_risk = df.groupby('Gender')[risk_factors].mean() * 100

    gender_risk.plot(kind='bar', figsize=(10, 6))
    plt.title("Risk Factors by Gender")
    plt.ylabel("Prevalence (%)")
    plt.xlabel("Gender")
    plt.show()


def ethnicity_vs_risk_factors(df):
    """Compare risk factors across ethnicities."""
    risk_factors = ['diabetes', 'hypertension', 'obesity', 'smoking']
    ethnicity_risk = df.groupby('Ethnicity')[risk_factors].mean() * 100

    ethnicity_risk.plot(kind='bar', figsize=(12, 6))
    plt.title("Risk Factors by Ethnicity")
    plt.ylabel("Prevalence (%)")
    plt.xlabel("Ethnicity")
    plt.show()


def healthscore_by_age_gender(df):
    """Compare health scores by age group and gender."""
    df['AgeGroup'] = pd.cut(df['Age'], bins=[0, 20, 40, 60, 80, 100], labels=['0-20', '21-40', '41-60', '61-80', '81+'])
    plt.figure(figsize=(10, 6))
    sns.boxplot(x='AgeGroup', y='HealthScore', hue='Gender', data=df)
    plt.title("HealthScore by Age Group and Gender")
    plt.ylabel("HealthScore")
    plt.xlabel("Age Group")
    plt.legend(title="Gender")
    plt.show()


def heatmap_risk_factors(df):
    """Create a heatmap for risk factor prevalence by age group and gender."""
    df['AgeGroup'] = pd.cut(df['Age'], bins=[0, 20, 40, 60, 80, 100], labels=['0-20', '21-40', '41-60', '61-80', '81+'])
    risk_factors = ['diabetes', 'hypertension', 'obesity', 'smoking']
    for factor in risk_factors:
        pivot_table = df.pivot_table(index='AgeGroup', columns='Gender', values=factor, aggfunc='mean') * 100
        sns.heatmap(pivot_table, annot=True, cmap="YlGnBu", fmt=".1f")
        plt.title(f"Prevalence of {factor.capitalize()} by Age Group and Gender")
        plt.ylabel("Age Group")
        plt.xlabel("Gender")
        plt.show()


def risk_factor_proportions(df):
    """Show the proportion of risk factors across the dataset."""
    risk_factors = ['diabetes', 'hypertension', 'obesity', 'smoking']
    proportions = df[risk_factors].mean() * 100

    plt.figure(figsize=(8, 6))
    proportions.plot(kind='bar', color="orange")
    plt.title("Proportion of Risk Factors in the Dataset")
    plt.ylabel("Prevalence (%)")
    plt.xlabel("Risk Factors")
    plt.show()
