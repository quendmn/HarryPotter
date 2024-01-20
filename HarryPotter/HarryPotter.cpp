#include <iostream>
#include <fstream>
#include<set>
#include<vector>
#include <algorithm>
#include <cctype>
#include <string>
#include <cstring>


void PrintSet(const std::set<std::string>& s) {
    for (const auto& i : s) {
        std::cout << " [" << i << "]" << "\n";
    }

}

void Erase(std::string &tmp, std::vector<std::string> &dictionary, std::set<std::string> &dictionary_set) {
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ','), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '.'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '\"'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '?'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '!'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '('), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ')'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ':'), tmp.end());
    tmp.erase(std::remove(tmp.begin(), tmp.end(), ';'), tmp.end());

    dictionary.push_back(tmp);
    dictionary_set.insert(tmp);
}

void PrintDictionary(std::vector<std::string> dictionary) {
    for (int i = 0; i < dictionary.size(); i++)
    {
        std::cout << dictionary[i] << ", " << "\n";
    }
}

int main()
{
    std::vector<std::string> dictionary;
    std::set<std::string> dictionary_set;

    std::ifstream book("J. K. Rowling - Harry Potter 1 - Sorcerer's Stone.txt");
    if (!book.is_open()) {
        std::cout << "Error\n";
    }
    else
    {
        while (!book.eof())
        {
            std::string tmp;
            book >> tmp;
            std::transform(tmp.begin(), tmp.end(), tmp.begin(),
                [](unsigned char c) { return std::tolower(c); });

            Erase(tmp, dictionary, dictionary_set);

        }
    }
    book.close();

    std::stable_sort(dictionary.begin(), dictionary.end());
    std::vector<std::string>::iterator it;
    it = unique(dictionary.begin(), dictionary.end());
    dictionary.resize(distance(dictionary.begin(), it));

    PrintSet(dictionary_set);
    PrintDictionary(dictionary);
}


