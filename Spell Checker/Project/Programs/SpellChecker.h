#pragma once
//Spell checker class
#include "HashTable.h"
#include <string>
#include <vector>

class SpellChecker
{
public:
    SpellChecker();
    ~SpellChecker();
    void spellCheck(HashTable table, std::string userWord);

private:
    std::vector<std::string> swapChar(std::string userWord);
    std::vector<std::string> insertChar(std::string userWord);
    std::vector<std::string> delChar(std::string userWord);
    std::vector<std::string> replaceChar(std::string userWord);
};