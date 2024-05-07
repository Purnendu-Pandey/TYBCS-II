import pandas as pd
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score, confusion_matrix, classification_report
import numpy as np
df=pd.read_csv("User_Data.csv")
print(df)
X = df[['Age','EstimatedSalary']]
y = df['Purchased']
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)
scaler = StandardScaler()
X_train_scaled = scaler.fit_transform(X_train)
X_test_scaled = scaler.transform(X_test)
model = LogisticRegression(random_state=25)
model.fit(X_train_scaled, y_train)
y_pred = model.predict(X_test_scaled)
print('y prediction: ',y_pred)
accuracy = accuracy_score(y_test, y_pred)
print("Model Evaluation")
print("Accuracy:", accuracy)
