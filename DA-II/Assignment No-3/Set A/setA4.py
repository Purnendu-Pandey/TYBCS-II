import nltk
import re
from nltk.corpus import stopwords
from nltk.tokenize  import word_tokenize,sent_tokenize
import matplotlib.pyplot as plt
from wordcloud import WordCloud
fnm=eval(input(" Enter file Name : "))
fp=open(fnm,"r",encoding='utf-8')
ct=fp.read()
print(ct)
sw=set(stopwords.words("english"))
print("\n Stopwords..... \n")
print(sw)
st=sent_tokenize(ct)
print("\n Sent Tokens..... \n")
print(st)
ft=[]
for w in st:
    if w not in sw:
        ft.append(w)
print("\n Text After removing Stopwords \n\n",ft)

wc=WordCloud(collocations=False,background_color="black").generate(ct)
plt.imshow(wc,interpolation="bilinear")
plt.axis("off")
plt.show()
