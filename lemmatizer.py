# lemmatizer.py
import sys
import spacy

nlp = spacy.load("en_core_web_sm")

text = " ".join(sys.argv[1:])
doc = nlp(text)

print(" ".join([token.lemma_ for token in doc]))
