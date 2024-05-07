import pandas as pd
from mlxtend.frequent_patterns import apriori,association_rules
from mlxtend.preprocessing import TransactionEncoder
df=pd.read_csv("Market_Basket_Optimisation.csv")
df=df.sample(50)
print(df)

transactions=[]
for i in range(0,len(df)):
     transactions.append([str(df.values[i,j])for j in range(0,len(df.columns)) if (str(df.values[i,j])!='nan')])
     
te=TransactionEncoder()
te_array=te.fit(transactions).transform(transactions)
dfe=pd.DataFrame(te_array,columns=te.columns_)
print(dfe)

freq_items=apriori(dfe,min_support=0.005,use_colnames=True)
print(freq_items)

rules=association_rules(freq_items,metric='support',min_threshold=0.005)
rules=rules.sort_values(['support','confidence'])
print(rules)


