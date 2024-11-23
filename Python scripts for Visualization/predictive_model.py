# predictive_model.py

from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report
import pandas as pd

def train_predictive_model(df):
    """Trains a health risk prediction model."""
    df = pd.get_dummies(df, columns=['Gender', 'Ethnicity'], drop_first=True)
    features = ['Age', 'HealthScore'] + [col for col in df.columns if col.startswith('Gender_') or col.startswith('Ethnicity_')]
    target = ['diabetes', 'hypertension', 'obesity', 'smoking']

    X = df[features]
    y = df[target]
    X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

    model = RandomForestClassifier(random_state=42)
    model.fit(X_train, y_train)

    y_pred = model.predict(X_test)

    # Suppress warnings for undefined metrics
    print("Classification Report:")
    print(classification_report(y_test, y_pred, target_names=target, zero_division=0))

    # Debug samples with no true labels
    no_true_labels = (y_test.sum(axis=1) == 0).sum()
    print(f"Samples with no true labels: {no_true_labels}")

    return model
