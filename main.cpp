/*
    Programmer: Zach Nett
    Date: 5/26/2020
    File: main.cpp
    Purpose: Practice multithreaded programming in C++
*/
#include "TextAnalyzer.hpp"


/*
    TODO: 
    >   keep track of data in struct/class for file printing
        (right now code does double the work that it needs to)
*/

void longWord(Analyzer a) {
    std::cout << "Longest word is " << a.findLongestWord() << std::endl;
}

void shortWord(Analyzer a) {
    std::cout << "Shortest word is " << a.findShortestWord() << std::endl;
}

void averageWordLength(Analyzer a) {
    std::cout << "Average word length is " << a.findAverageWordLength() << std::endl;
}

void mostCommonWords(Analyzer a) {
    std::vector<std::string> most_common_words = a.findMostCommonWords();
    a.printCommonWords(most_common_words);
}

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cout << "Unexpected argument count, usage:\n./a.out <filename>" << std::endl;
        return 1;
    }
    const std::string filename(argv[1]);

    Analyzer a;

    std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

    if (a.loadText(filename)) {
        //          SINGLE-THREADED SECTION
        /*std::cout << "Longest word is " << a.findLongestWord() << std::endl;
        std::cout << "Shortest word is " << a.findShortestWord() << std::endl;
        std::cout << "Average word length is " << a.findAverageWordLength() << std::endl;
        std::vector<std::string> most_common_words = a.findMostCommonWords();
        a.printCommonWords(most_common_words);*/

        std::cout << "Text loaded successfully!" << std::endl;
        a.printFrequency();

        //          MULTI-THREADED SECTION
        std::thread long_word_thread(longWord, a);
        std::thread short_word_thread(shortWord, a);
        std::thread average_word_length_thread(averageWordLength, a);
        std::thread most_common_words_thread(mostCommonWords, a);

        long_word_thread.join();
        short_word_thread.join();
        average_word_length_thread.join();
        most_common_words_thread.join();

        std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> time_took = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);

        a.printWordCount();
        std::cout << "Program took " << time_took.count() << " seconds to calculate." << std::endl;

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