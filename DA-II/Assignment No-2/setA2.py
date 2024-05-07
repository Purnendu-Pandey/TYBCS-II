import pandas as pd
from mlxtend.frequent_patterns import apriori,association_rules
from mlxtend.preprocessing import TransactionEncoder
transactions=[['Dog','Parrot'],
	     ['Dog','Fish','Rabbit','Cat'],
	     ['Parrot','Fish','Rabbit','Frog'],
	     ['Dog','Parrot','Fish','Rabbit'],
	     ['Dog','Parrot','Fish','Frog']]
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
ty32@pc37:~/TYBCS(VI)-32/DA/Assinment No-2$ python3 setA2.py
     Cat    Dog   Fish   Frog  Parrot  Rabbit
0  False   True  False  False    True   False
1   True   True   True  False   False    True
2  False  False   True   True    True    True
3  False   True   True  False    True    True
4  False   True   True   True    True   False
Frequent Itemsets
   support        itemsets
0      0.8           (Dog)
1      0.8          (Fish)
2      0.8        (Parrot)
3      0.6        (Rabbit)
4      0.6     (Fish, Dog)
5      0.6   (Dog, Parrot)
6      0.6  (Fish, Parrot)
7      0.6  (Rabbit, Fish)
  antecedents consequents  ...  conviction  zhangs_metric
6    (Rabbit)      (Fish)  ...         inf           0.50
0      (Fish)       (Dog)  ...         0.8          -0.25
1       (Dog)      (Fish)  ...         0.8          -0.25
2       (Dog)    (Parrot)  ...         0.8          -0.25
3    (Parrot)       (Dog)  ...         0.8          -0.25
4      (Fish)    (Parrot)  ...         0.8          -0.25
5    (Parrot)      (Fish)  ...         0.8          -0.25
7      (Fish)    (Rabbit)  ...         1.6           1.00

[8 rows x 10 columns]
"""
