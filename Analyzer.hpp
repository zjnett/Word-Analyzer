#pragma once
#include "TextAnalyzer.hpp"

class Analyzer {
public:
    Analyzer() : id("") {}
    ~Analyzer() {}

    void setID(const std::string &new_id) { id = new_id; }
    std::string getID() { return id; }

    int getWordCount() { return word_count; }

    // Loads text from file with const string filename.
    // Returns true if file could be opened, false otherwise.
    bool loadText(const std::string &filename);
    // Prints all keys and values in frequency map.
    void printFrequency();
    // Finds longest word in frequency list
    std::string findLongestWord();
    // Finds average word length in frequency list
    double findAverageWordLength();
    // Prints current word count.
    void printWordCount() { std::cout << "Word Count: " << word_count << std::endl; }
    // Prints all relevant data to a file.
    bool printDataToFile();

private:
    //      Private utility functions
    // Removes non-alphanumeric characters from a word, returns processed word.
    std::string processWord(std::string &s);
    std::string removeExtension(const std::string &s);

    //      Data members
    std::string id;
    int word_count;
    std::unordered_map<std::string, int> frequency;
};

bool Analyzer::loadText(const std::string &filename) {
    bool status = false;
    std::fstream file;
    file.open(filename);
    if (file.is_open()) {
        setID(removeExtension(filename));
        std::string word = "";
        while (file >> word) {
            word = processWord(word);
            frequency[word]++;
            word_count++;
        }
        status = true;
    }
    return status;
}

std::string Analyzer::processWord(std::string &s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
    return s;
}

std::string Analyzer::findLongestWord() {
    std::string longest_word = frequency.begin()->first;
    for (std::pair<std::string, int> word : frequency) {
        if (word.first.length() > longest_word.length())
            longest_word = word.first;
    }
    return longest_word;
}

double Analyzer::findAverageWordLength() {
    int sum_word_lengths = 0;
    for (std::pair<std::string, int> word : frequency) {
        // multiply length of word by frequency of word, add to sum
        sum_word_lengths += word.first.length() * word.second;
    }
    return (double) sum_word_lengths / word_count;
}

std::string Analyzer::removeExtension(const std::string &s) {
    size_t last_index = s.find_last_of(".");
    std::string n_string = s.substr(0, last_index);
    return n_string;
}

void Analyzer::printFrequency() {
    for (std::pair<std::string, int> word : frequency) {
        std::cout << "Word: " << word.first << "\tFrequency: " << word.second << std::endl;
    }
}

bool Analyzer::printDataToFile() {
    bool status = false;
    std::string filename = id + "-data.txt";
    std::ofstream file;
    file.open(filename);
    if (file.is_open()) {
        for (std::pair<std::string, int> word : frequency) {
            file << "Word: " << word.first << "\tFrequency: " << word.second << std::endl;
        }
        file << "Longest word is " << findLongestWord() << std::endl;
        file << "Average word length is " << findAverageWordLength() << std::endl;
        file << "Word Count: " << word_count << std::endl;
        file.close();
        status = true;
    }
    return status;
}

/*

a.findAverageWordLength();
    a.findShortestWord();
    a.findMostCommonWords();

*/