import pandas as pd
import numpy as np

from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import r2_score, mean_squared_error, mean_absolute_error
from sklearn.preprocessing import StandardScaler
import joblib

import matplotlib.pyplot as plt
%matplotlib inline

from google.colab import files
uploaded = files.upload()

print("Uploaded files:", list(uploaded.keys()))

file = 'road_accident_data.xlsx'

df = pd.read_excel(file)

print("Rows, Columns:", df.shape)
display(df.head())
df.info()

print("Missing values per column:\n", df.isna().sum())

display(df.describe())

categorical_cols = ['Weather_Condition','Road_Type','Alcohol_Involved']
for c in categorical_cols:
    if c in df.columns:
        print(c, "unique values:", df[c].unique())

required = ['Accident_Severity','Vehicle_Speed','Weather_Condition','Road_Type','Driver_Age','Alcohol_Involved']
missing = [c for c in required if c not in df.columns]
if missing:
    raise ValueError("Missing required columns: " + ", ".join(missing))

X = df[['Vehicle_Speed','Weather_Condition','Road_Type','Driver_Age','Alcohol_Involved']].copy()
y = df['Accident_Severity'].copy()

print("X shape:", X.shape, "y shape:", y.shape)
display(X.head())

numeric_cols = ['Vehicle_Speed','Driver_Age']
scaler = StandardScaler()
X[numeric_cols] = scaler.fit_transform(X[numeric_cols])

joblib.dump(scaler, 'scaler.joblib')
print("Scaler saved as scaler.joblib")
display(X.head())

X_train, X_test, y_train, y_test = train_test_split(
    X, y, test_size=0.2, random_state=42
)

print("Train shapes:", X_train.shape, y_train.shape)
print("Test shapes:", X_test.shape, y_test.shape)

model = LinearRegression()
model.fit(X_train, y_train)
print("Model trained.")

coef_df = pd.DataFrame({
    'feature': X_train.columns,
    'coefficient': model.coef_
}).sort_values(by='coefficient', key=abs, ascending=False)

display(coef_df)
print("Intercept:", model.intercept_)

y_pred = model.predict(X_test)

r2 = r2_score(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)
mae = mean_absolute_error(y_test, y_pred)

print(f"R²: {r2:.4f}")
print(f"MSE: {mse:.4f}")
print(f"MAE: {mae:.4f}")

# Predicted vs actual
plt.figure()
plt.scatter(y_test, y_pred)
plt.xlabel('Actual Severity')
plt.ylabel('Predicted Severity')
plt.title('Actual vs Predicted')
plt.grid(True)
plt.show()

# Residuals histogram
residuals = y_test - y_pred
plt.figure()
plt.hist(residuals, bins=10)
plt.title('Residuals Distribution')
plt.xlabel('Residual')
plt.show()

# Save the model
joblib.dump(model, 'accident_severity_model.pkl')
print("Model saved as accident_severity_model.pkl")

scaler = joblib.load('scaler.joblib')

example_dict = {
    'Vehicle_Speed': [95],
    'Weather_Condition': [1],
    'Road_Type': [2],
    'Driver_Age': [28],
    'Alcohol_Involved': [1]
}
example_df = pd.DataFrame(example_dict)

example_df[['Vehicle_Speed','Driver_Age']] = scaler.transform(example_df[['Vehicle_Speed','Driver_Age']])


example_df = example_df[X_train.columns]

pred = model.predict(example_df)[0]
print("Raw predicted severity (continuous):", pred)

pred_rounded = int(round(pred))
pred_rounded = max(min(pred_rounded, df['Accident_Severity'].max()), df['Accident_Severity'].min())
print("Predicted severity (rounded to nearest class):", pred_rounded)
