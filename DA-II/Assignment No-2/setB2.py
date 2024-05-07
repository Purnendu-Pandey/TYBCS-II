import pandas as pd
from mlxtend.frequent_patterns import apriori, association_rules
from mlxtend.preprocessing import TransactionEncoder
df = pd.read_csv('Groceries_dataset.csv')
df=df.sample(50)
print(df) 

transaction=[]
for i in range(0,len(df)):
    transaction.append([str(df.values[i,j]) for j in range(0,len(df.columns)) if (str(df.values[i,j])!='nan')])   	

te=TransactionEncoder()
arr=te.fit(transaction).transform(transaction)  
df1=pd.DataFrame(arr,columns=te.columns_)        
print(df1)

freq_itemset=apriori(df1,min_support=0.005,use_colnames=True)
print("Frequent Itemsets:\n",freq_itemset)

rules=association_rules(freq_itemset,metric='support',min_threshold=0.005)
rules=rules.sort_values(['support','confidence'])
print("Association rules:\n",rules)
