#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "HashItem.h"

#include <map>
#include <string>
#include <vector>

class HashTable {
    public:
        HashTable();

        void insert(char *key, char *type, void *value);

        HashItem *get(char *key);

        char *getHItemType(HashItem *item);

        void *getHItemValue(HashItem *item);

        std::vector<std::string> getKeys();
    
    private:
        std::map<std::string, HashItem*> *hashTable;
};

#endif