#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <cstdlib>

std::string getLemmas(const std::string& text) {
    std::string command = "python3 lemmatizer.py \"" + text + "\" > lemma_result.txt";
    system(command.c_str());

    std::ifstream result("lemma_result.txt");
    std::string lemmas;
    std::getline(result, lemmas);
    result.close();

    return lemmas;
}

std::vector<std::string> split(const std::string& s) {
    std::istringstream iss(s);
    std::vector<std::string> words;
    std::string word;
    while (iss >> word) {
        words.push_back(word);
    }
    return words;
}

int main() {
    std::vector<std::string> filenames = {"tiger.txt", "elephant.txt", "Asian_Elephant.txt","Red_Panda.txt","Bengal_Tiger.txt"};

    std::cout << "Enter a word to search: ";
    std::string query;
    std::getline(std::cin, query);

    std::string queryLemma = getLemmas(query);
    std::cout << "Searching for lemma: " << queryLemma << std::endl;

    for (const std::string& filename : filenames) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Could not open file: " << filename << std::endl;
            continue;
        }

        std::cout << "Reading file: " << filename << std::endl;
        std::string line;
        int line_number = 0;

        bool match_found = false;

        while (std::getline(file, line)) {
            line_number++;

            std::string lineLemmas = getLemmas(line);
            std::vector<std::string> lemmasInLine = split(lineLemmas);

            int count=0;

            for(const std::string& lemma : lemmasInLine){
                if(lemma==queryLemma){
                    count++;
                }
            }

            if (count > 0) {
                match_found = true;
                std::cout << "Line " << line_number << ": " << count << " appearance(s)" << std::endl;
            }
            
        }

        if (!match_found) {
            std::cout << "No matches found" << std::endl;
        }

        file.close();
        std::cout << "----------------------------" << std::endl;
    }

    return 0;
}

