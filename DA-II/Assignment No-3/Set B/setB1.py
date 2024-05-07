import pandas as pd
import matplotlib.pyplot as plt
from wordcloud import WordCloud
from nltk.corpus import stopwords
from nltk.tokenize import word_tokenize,sent_tokenize
df = pd.read_csv('msd.csv')
print(df)
top_5_infl= df[df['Audience Country'] == 'India'].nlargest(5, 'Followers')
print("Top 5 Instagram influencers from India:")
print(top_5_infl[['Account', 'Followers']])

l_f_acc = df.loc[df['Followers'].idxmin()]
print("\nInstagram account with least number of followers:")
print(l_f_acc[['Account', 'Followers']])


stop_words = set(stopwords.words('english'))
category_text = ' '.join(df['Category'].dropna())
word_tokens = word_tokenize(category_text)
filtered_category_words = [word.lower() for word in word_tokens if word.lower() not in stop_words]
wordcloud = WordCloud(width=800, height=400, background_color='white').generate(' '.join(filtered_category_words))
plt.figure(figsize=(10, 5))
plt.imshow(wordcloud, interpolation='bilinear')
plt.axis('off')
plt.title('Word Cloud of Instagram Influencers Categories (After Removing Stopwords)')
plt.show()


grouped_by_category = df.groupby('Category')
print("\nInstagram accounts grouped by category:")
for category, group in grouped_by_category:
    print("\nCategory:", category)
    print(group[['Account', 'Followers']])

plt.figure(figsize=(10, 6))
plt.scatter(df['Followers'], df['Authentic engagement'])
plt.title('Relationship between Followers and Authentic Engagement')
plt.xlabel('Followers')
plt.ylabel('Authentic Engagement')
plt.grid(True, which='both', linestyle='--', linewidth=0.5)
plt.show()
