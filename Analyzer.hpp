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
    // Prints current word count.
    void printWordCount() { std::cout << "Word Count: " << word_count << std::endl; }

private:
    std::string processWord(std::string s);
    std::string id;
    int word_count;
    std::unordered_map<std::string, int> frequency;
};

bool Analyzer::loadText(const std::string &filename) {
    bool status = false;
    std::fstream file;
    file.open(filename);
    if (file.is_open()) {
        setID(filename);
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

std::string Analyzer::processWord(std::string s) {
    s.erase(std::remove_if(s.begin(), s.end(), [](char c) { return !isalpha(c); } ), s.end());
    return s;
}

void Analyzer::printFrequency() {
    for (std::pair<std::string, int> word : frequency) {
        std::cout << "Word: " << word.first << "\tFrequency: " << word.second << std::endl;
    }
}

/*

a.findAverageWordLength();
    a.findLongestWord();
    a.findShortestWord();
    a.findMostCommonWords();

*/