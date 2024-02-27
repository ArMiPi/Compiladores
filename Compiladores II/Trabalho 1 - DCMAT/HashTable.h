#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <map>

typedef struct _hitem htItem;

class HashTable {
    public:
        HashTable();

        void insert(char *key, char *type, void *value);

        htItem *get(char *key);

        char *getHItemType(htItem *item);

        void *getHItemValue(htItem *item);
    
    private:
        std::map<char*, htItem*> *hashTable;
};

#endif