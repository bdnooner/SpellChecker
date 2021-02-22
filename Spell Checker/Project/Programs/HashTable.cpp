#include "HashTable.h"
#include <fstream>


using namespace std;

//constructor for hashTable
HashTable::HashTable()
{
    this->numBuckets = 100;
    buckets = new BucketList[numBuckets];
    for (int i = 0; i < numBuckets; ++i)
        buckets[i].head = NULL;
}

//Destructor for hashTable
HashTable::~HashTable() { }

void HashTable::addItems(string word)
{
    BucketNode* newNode = new BucketNode;

    for (int i = 0; i < int(word.length()); ++i)
    {
        word[i] = tolower(word[i]);
    }
    int hashKey = hashFunc(word);

    newNode->key = hashKey;
    newNode->value = word;

    newNode->next = buckets[hashKey].head;
    buckets[hashKey].head = newNode;
}

bool HashTable::searchTable(string userWord)
{
    bool found = false;
    int hashKey = hashFunc(userWord);
    BucketNode* temp = buckets[hashKey].head;

    while (temp)
    {
        if (temp->value == userWord)
        {
            found = true;
            break;
        }
        else
            temp = temp->next;
    }

    return found;
}

/***********************
*  Private Functions   *
* ******************** */

//hash for the string values 
int HashTable::hashFunc(string word)
{
    int hash = 0;
    for (int i = 0; i < int(word.length()); i++)
        hash += (int(word[i]));

    return hash % numBuckets;
}
