import nltk
from nltk.sentiment.vader import SentimentIntensityAnalyzer
import pandas as pd
nltk.download('vader_lexicon')
import matplotlib.pyplot as plt
from wordcloud import WordCloud
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize,sent_tokenize

df=pd.read_csv('covid_2021_1.csv')
print(df)

ct=df['comment_text']
print("\n",ct,"\n")

print(df.isnull().sum())
sw=set(stopwords.words("english"))
print("stopwords")
print(sw)

print("word tokens")

vd=SentimentIntensityAnalyzer()
wd={}
for w in ct:
    wd=word_tokenize(w)
    print(wd)
    print("\n ",vd.polarity_scores(w))
