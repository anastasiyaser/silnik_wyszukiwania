#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

string getLemmas(const string& text) {
    string command = "python3 lemmatizer.py \"" + text + "\" > lemma_result.txt";
    system(command.c_str());

    ifstream result("lemma_result.txt");
    string lemmas;
    getline(result, lemmas);
    result.close();

    return lemmas;
}

vector<string> split(const string& s) {
    istringstream iss(s);
    vector<string> words;
    string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    vector<string> filenames = {"tiger.txt", "elephant.txt", "Asian_Elephant.txt","Red_Panda.txt","Bengal_Tiger.txt"};

    cout << "Enter a word to search: ";
    string query;
    getline(cin, query);

    string queryLemma = getLemmas(query);
    cout << "Searching for lemma: " << queryLemma << endl;

    for (const string& filename : filenames) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Could not open file: " << filename << endl;
            continue;
        }

        cout << "Reading file: " << filename << endl;
        string line;
        int line_number = 0;

        bool match_found = false;

        while (getline(file, line)) {
            line_number++;

            string lineLemmas = getLemmas(line);
            vector<string> lemmasInLine = split(lineLemmas);

            int count=0;

            for(const string& lemma : lemmasInLine){
                if(lemma==queryLemma){
                    count++;
                }
            }

            if (count > 0) {
                match_found = true;
                cout << "Line " << line_number << ": " << count << " appearance(s)" << endl;
            }
            
        }

        if (!match_found) {
            cout << "No matches found" << endl;
        }

        file.close();
        cout << "----------------------------" << endl;
    }

    return 0;
}
