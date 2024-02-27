#include "HashTable.h"

#include <iostream>

struct _hitem {
    char *type;
    void *value;
};

HashTable::HashTable() {
    this->hashTable = new std::map<char*, htItem*>();
}

void HashTable::insert(char *key, char *type, void *value) {
    htItem *item = (htItem *) malloc(sizeof(htItem));
    if(!item) {
        std::cout << "Não foi possível alocar novo item para HashTable" << std::endl;
        return;
    }

    item->type = type;
    item->value = value;

    this->hashTable->insert(std::pair<char*, htItem*>(key, item));
}

htItem *HashTable::get(char *key) {
    
}

