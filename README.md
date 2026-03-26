# Search Engine - spaCy-Based Text Lemmatization Search

## Project Description

This is a text search program that uses lemmatization powered by spaCy. The program allows you to search for words in multiple English text files, taking into account different forms of the same word (lemmatization).

## Features

- 🔍 Word search by root form (lemma) using spaCy
- 📄 Simultaneous search across multiple files
- 📍 Output of line numbers with found matches
- 🔢 Count of found word forms on each line
- 🐍 Integration with Python for English text lemmatization using spaCy

## Requirements

- **C++ compiler** (g++, clang)
- **Python 3**
- **spaCy** - Natural Language Processing library (English support)
- **en_core_web_sm** - spaCy model for English language

### Installing Dependencies

```bash
pip3 install spacy
python3 -m spacy download en_core_web_sm
```

## Project Files

- `projekt.cpp` - main source code in C++
- `projekt` - compiled executable file
- `lemmatizer.py` - Python script for text lemmatization
- `tiger.txt`, `elephant.txt`, `Asian_Elephant.txt`, `Red_Panda.txt`, `Bengal_Tiger.txt` - text files for searching

## Compilation

If you need to rebuild the program:

```bash
g++ -o projekt projekt.cpp
```

## Running the Program

```bash
./projekt
```

### Usage Example

```
$ ./projekt
Enter a word to search: tiger
Searching for lemma: tiger

Reading file: tiger.txt
Line 1: 2 appearance(s)
Line 5: 1 appearance(s)
----------------------------

Reading file: elephant.txt
No matches found
----------------------------

Reading file: Asian_Elephant.txt
No matches found
----------------------------

Reading file: Red_Panda.txt
No matches found
----------------------------

Reading file: Bengal_Tiger.txt
Line 3: 1 appearance(s)
----------------------------
```

## How It Works

1. The program prompts for a word to search
2. The word is passed to the `lemmatizer.py` script, which uses spaCy for English text analysis
3. spaCy finds the lemma (root form) of the word
4. The program searches for this lemma in all text files
5. For each line, the number of found matches is displayed
6. Results are saved to the `lemma_result.txt` file

## Code Structure

- **getLemmas()** - function to get the lemma of a word through Python
- **split()** - function to split text into words
- **main()** - main function that manages the search process

## Author

Project completed as part of the "Wstęp do programowania" (Introduction to Programming) course
Year 1, Semester 1

## Notes

- The program searches for exact lemma matches
- Letter case is not considered (handled by spaCy)
- Search results are output by file in the order they are specified in the code
- The project is designed for analyzing **English texts**
- First run may take time to load the spaCy model
- Uses the spaCy `en_core_web_sm` model for accurate English lemmatization



