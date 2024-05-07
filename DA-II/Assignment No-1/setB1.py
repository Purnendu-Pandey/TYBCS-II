import numpy as np
import pandas as pd
from sklearn import metrics
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
df=pd.read_csv("Fish.csv")
X=df.iloc[:,[2]].values
y=df.iloc[:,[1]].values
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.3, random_state=42)

model = LinearRegression()
model.fit(X_train, y_train)

print("Training set:")
print(X_train)
print(y_train)
print("\nTesting set:")
print(X_test)
print(y_test)

print("\nCoefficients:", model.coef_)
print("Intercept:", model.intercept_)

y_pred = model.predict(X_test)
print('y prediction: ',y_pred)

mse = metrics.mean_squared_error(y_test, y_pred)
rmse = np.sqrt(mse)
print("\nModel Evaluation:")
print("Mean Squared Error (MSE):", mse)
print("Root Mean Squared Error (RMSE):", rmse)

print("Coefficients:",model.coef_)
print("Intercept:",model.intercept_)