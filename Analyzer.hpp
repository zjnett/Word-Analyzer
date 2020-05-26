#pragma once
#include "TextAnalyzer.hpp"

class Analyzer {
public:
    Analyzer() : ID("ID123") {}
    void print() { std::cout << getID() << std::endl; }
    std::string getID() { return ID; }
private:
    std::string ID;
};