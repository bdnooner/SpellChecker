#include "HashTable.h"
#include "SpellChecker.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// fucnction to read words from a file and store them into a list for manipulation
vector<string> readFile(string file_name)
{
    vector<string> words;
    ifstream wordList(file_name, ios::in); // Open input filestream
    if (wordList.is_open())
    {
        while (!wordList.eof())
        {
            string dataBuffer;
            getline(wordList, dataBuffer, '\n');
            words.push_back(dataBuffer);
        }
    }
    else
    {
        cout << "File is cannot be opened!";
    }

    wordList.close();
    return words;
}

int main()
{
    vector<string> words = readFile("dictionary.txt");
    string userWord;

    HashTable table;

    for (int i = 0; i < int(words.size()); ++i)
    {
        table.addItems(words[i]);
    }

    cout << "Welcome to Spell Checker!\n"
        << "Type a word to see if it is spelled correctly, or type \"quit\" to exit:\t";

    cin >> userWord;

   
   do
   {
        //convert user input to all lowercase for easier testing
        for (int i = 0; i < int(userWord.length()); ++i)
        {
            userWord[i] = tolower(userWord[i]);
        }

        SpellChecker checker;
        checker.spellCheck(table, userWord);

        cout << "\n\nWould you like to go again?\n"
            << "Type \"quit\" to exit or another word to check:\t";

   
        cin >> userWord;

   } while (userWord != "quit");

}
