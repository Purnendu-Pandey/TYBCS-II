import nltk
import re
from nltk.corpus import stopwords
from nltk.tokenize  import word_tokenize,sent_tokenize
from nltk.probability import FreqDist
import matplotlib.pyplot as plt
from wordcloud import WordCloud
te=" Text semmerisation is an nlp technique that extract text from a large amount of data. It is the process of identifying the most meanigful information in a document and compressing it into a shorter version by preserving its meaning. @ $ Types 12 : Extractive Text Summerisation "
print("\n Text is.....\n")
print(te)
sw=set(stopwords.words("english"))
print("\n Stopwords..... \n")
print(sw)
st=sent_tokenize(te)
print("\n Sent Tokens..... \n")
print(st)
wd=word_tokenize(te)
print("\n Word Tokens..... \n")
print(wd)
ft=[]
for w in wd:
    if w not in sw:
        ft.append(w)
print("\n Text After removing Stopwords \n ",ft)
#freq of words
fd=FreqDist(wd)
print("\n",fd)
#freq Graph
fd.plot(49,cumulative=False)
plt.show()
#wc of text
wc=WordCloud(collocations=False,background_color="black").generate(te)
plt.imshow(wc,interpolation="bilinear")
plt.axis("off")
plt.show()
