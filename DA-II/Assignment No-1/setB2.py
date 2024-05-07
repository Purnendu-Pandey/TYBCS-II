import pandas as pd
from sklearn.datasets import load_iris
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LogisticRegression
from sklearn.metrics import accuracy_score

iris = load_iris()
df = pd.DataFrame(iris.data, columns=iris.feature_names)
df['target'] = iris.target

print("Statistical details of Iris-setosa:")
print(df[df['target'] == 0].describe())

print("Statistical details of Iris-versicolor:")
print(df[df['target'] == 1].describe())

print("Statistical details of Iris-virginica:")
print(df[df['target'] == 2].describe())

X = df.iloc[:, :-1]
y = df['target'] 
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

logreg = LogisticRegression(max_iter=1000)
logreg.fit(X_train, y_train)

y_pred = logreg.predict(X_test)
accuracy = accuracy_score(y_test, y_pred)
print("Accuracy of the logistic regression model:", accuracy)