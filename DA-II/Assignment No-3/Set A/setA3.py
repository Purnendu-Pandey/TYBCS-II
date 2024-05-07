import nltk
nltk.download('vader_lexicon')
from nltk.sentiment.vader import SentimentIntensityAnalyzer
vd=SentimentIntensityAnalyzer()
te=" I purchased Mango online. I am very happy with product "
print("\n",vd.polarity_scores(te))
te=" I hate tea  "
print("\n",vd.polarity_scores(te))
te=" I saw movie yesterday. The animation was really good but script was ok "
print("\n",vd.polarity_scores(te))
te=" I enjoy listning music "
print("\n",vd.polarity_scores(te))
