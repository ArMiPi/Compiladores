#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashItem.h"

#include <map>

class HashTable {
    public:
        HashTable();

        void insert(char *key, char *type, void *value);

        HashItem *get(char *key);

        char *getHItemType(HashItem *item);

        void *getHItemValue(HashItem *item);
    
    private:
        std::map<char*, HashItem*> *hashTable;
};

#endif