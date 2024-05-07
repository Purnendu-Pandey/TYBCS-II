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
print(df.isnull().sum())

