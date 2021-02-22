#include "SpellChecker.h"
#include <iostream>

using namespace std;

//Constructor
SpellChecker::SpellChecker() { }
SpellChecker::~SpellChecker() { }

void SpellChecker::spellCheck(HashTable table, string userWord)
{
    if (table.searchTable(userWord))
        cout << userWord << " was spelled correctly!\n\n";

    else
    {
        vector<string> suggestions;
        vector<string> alteredWords = swapChar(userWord);

        //test for possible intended words when swapping chars in the original word
        for (int i = 0; i < int(alteredWords.size()); ++i)
        {
            if (table.searchTable(alteredWords[i]))
                suggestions.push_back(alteredWords[i]);
        }

        //test for possible intended words when deleting chars in the original word
        alteredWords = delChar(userWord);
        for (int i = 0; i < int(alteredWords.size()); ++i)
        {
            if (table.searchTable(alteredWords[i]))
                suggestions.push_back(alteredWords[i]);
        }

        //test for possible intended words when replacing chars in the original word
        alteredWords = replaceChar(userWord);
        for (int i = 0; i < int(alteredWords.size()); ++i)
        {
            if (table.searchTable(alteredWords[i]))
                suggestions.push_back(alteredWords[i]);
        }

        //test for possible intended words when insterting chars in the original word
        alteredWords = insertChar(userWord);
        for (int i = 0; i < int(alteredWords.size()); ++i)
        {
            if (table.searchTable(alteredWords[i]))
                suggestions.push_back(alteredWords[i]);
        }

        cout << userWord << " does not appear in our list. Did you mean to type:\n\n";

        for (int i = 0; i < int(alteredWords.size()); ++i)
        {
            cout << suggestions[i] << "    ";
            if (i > 1 && i % 5 == 0)      // new line every 5 words to make it easier to read
                cout << endl;
        }

        suggestions.clear();
        alteredWords.clear();
    }


}

vector<string> SpellChecker::swapChar(string userWord)
{
    vector<string> swappedWords;

    for (int i = 0; i < userWord.size(); ++i)
    {
        string tempWord = userWord;         //make a copy of original word to manipulate
        swap(tempWord[i], tempWord[i + 1]); // swap two characters at i and i+1 through 
                                            //every iteration 

        swappedWords.push_back(tempWord);
    }

    return swappedWords;
}

vector<string>  SpellChecker::insertChar(string userWord)
{
    vector<string> injectedWords; //list of words that we have added chars to 

    for (int i = 0; i < userWord.size(); ++i)
    {
        for (int j = 97; j < 123; j++)
        {
            string tempWord = userWord;    //make a copy of original word to manipulate
            string temp;                   //used to store the char we want to inject
            temp = int(j);                 //convert j into the char that we are at

            tempWord.insert(i, temp);

            injectedWords.push_back(tempWord);
        }
    }

    return injectedWords;
}

vector<string>  SpellChecker::delChar(string userWord)
{
    vector<string> delCharWords; //list of words that we have deleted chars from 

    string tempWord = " ";
    string prevWord;

    for (int i = 0; i < userWord.size(); ++i)
    {
        prevWord = tempWord;
        tempWord = userWord;

        tempWord.erase(tempWord.begin() + i); // delete char at i
             
        if(tempWord != prevWord)
            delCharWords.push_back(tempWord);
        
    }

    return delCharWords;
}

vector<string>  SpellChecker::replaceChar(string userWord)
{
    vector<string> replacedCharWords; //list of words that we have replaced chars in 

    for (int i = 0; i < userWord.size(); ++i)
    {
        for (int j = 97; j < 123; j++)
        {
            string tempWord = userWord;    //make a copy of original word to manipulate
            string temp;                   //used to store the char we want to inject
            char c = j;                   //convert j into the char that we are at

            tempWord[i] = c;              //replace the char at i 

            replacedCharWords.push_back(tempWord);
        }
    }

    return replacedCharWords;
}

