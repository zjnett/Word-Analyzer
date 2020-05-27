/*
    Programmer: Zach Nett
    Date: 5/26/2020
    File: main.cpp
    Purpose: Practice multithreaded programming in C++
*/
#include "TextAnalyzer.hpp"

/*
    TODO:
    >   Load text (.txt file, into what data structure?)
    >   Find average word length
    >   Find longest word
    >   Find shortest word
    >   Find most common words
*/

int main(void) {
    Analyzer a;
    if (a.loadText("290-essay.txt")) {
        // if text could be loaded successfully
        std::cout << "Text loaded successfully!" << std::endl;
        a.printFrequency();
        std::cout << "Longest word is " << a.findLongestWord() << std::endl;
        a.printWordCount();
        if (a.printDataToFile()) {
            std::cout << "Successfully wrote to file!\n";
        } else {
            std::cout << "Error writing to file!\n";
        }
    } else {
        std::cout << "Error loading text." << std::endl;
    }
    /*a.loadText("name.txt");
    a.findAverageWordLength();
    a.findLongestWord();
    a.findShortestWord();
    a.findMostCommonWords();*/
    return 0;
}