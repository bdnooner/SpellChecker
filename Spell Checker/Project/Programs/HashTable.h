#pragma once
//Hash Table using single chaining with a linked list
#include <string>
#include <vector>

struct BucketNode
{
    int key;
    std::string value;
    BucketNode* next = NULL;
};

struct BucketList
{
    BucketNode* head;
};

class HashTable
{
public:
    HashTable();
    ~HashTable();
    void addItems(std::string word);
    bool searchTable(std::string userWord);


private:
    BucketList* buckets; //pointers to an array of buckets
    int numBuckets; // number of buckets to use
    int hashFunc(std::string word); //hash functi
};