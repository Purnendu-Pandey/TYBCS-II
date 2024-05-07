import pandas as pd
from mlxtend.frequent_patterns import apriori,association_rules
from mlxtend.preprocessing import TransactionEncoder
transactions=[['Bread','Milk'],
	     ['Bread','Diaper','Beer','Eggs'],
	     ['Milk','Diaper','Beer','Coke'],
	     ['Bread','Milk','Diaper','Beer'],
	     ['Bread','Milk','Diaper','Coke']]
te=TransactionEncoder()
te_array=te.fit(transactions).transform(transactions)
df=pd.DataFrame(te_array, columns=te.columns_)
print(df)

freq_items=apriori(df, min_support=0.5, use_colnames=True)
print("Frequent Itemsets")
print(freq_items)


rules=association_rules(freq_items,metric='support', min_threshold=0.05)
rules=rules.sort_values(['support','confidence'],ascending=[False,False])
print(rules)
	 
"""
ty32@pc37:~/TYBCS(VI)-32/DA/Assinment No-2$ python3 setA1.py
    Beer  Bread   Coke  Diaper   Eggs   Milk
0  False   True  False   False  False   True
1   True   True  False    True   True  False
2   True  False   True    True  False   True
3   True   True  False    True  False   True
4  False   True   True    True  False   True
Frequent Itemsets
   support         itemsets
0      0.6           (Beer)
1      0.8          (Bread)
2      0.8         (Diaper)
3      0.8           (Milk)
4      0.6   (Diaper, Beer)
5      0.6  (Diaper, Bread)
6      0.6    (Milk, Bread)
7      0.6   (Diaper, Milk)
  antecedents consequents  ...  conviction  zhangs_metric
1      (Beer)    (Diaper)  ...         inf           0.50
0    (Diaper)      (Beer)  ...         1.6           1.00
2    (Diaper)     (Bread)  ...         0.8          -0.25
3     (Bread)    (Diaper)  ...         0.8          -0.25
4      (Milk)     (Bread)  ...         0.8          -0.25
5     (Bread)      (Milk)  ...         0.8          -0.25
6    (Diaper)      (Milk)  ...         0.8          -0.25
7      (Milk)    (Diaper)  ...         0.8          -0.25

[8 rows x 10 columns]
"""
