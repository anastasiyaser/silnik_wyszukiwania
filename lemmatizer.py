# lemmatizer.py
import sys
import spacy

nlp = spacy.load("en_core_web_sm")

# Получаем строку из аргументов
text = " ".join(sys.argv[1:])
doc = nlp(text)

# Выводим леммы через пробел
print(" ".join([token.lemma_ for token in doc]))
