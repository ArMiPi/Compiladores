#include "HashTable.h"

#include <iostream>

HashTable::HashTable() {
    this->hashTable = new std::map<std::string, HashItem*>();
}

void HashTable::insert(char *key, char *type, void *value) {
    /* Chave já existe */
    if(this->hashTable->find(std::string(key)) != this->hashTable->end()) {
        HashItem *it = get(key);

        it->redefineValues(type, value);

        return;
    }

    HashItem *item = new HashItem(type, value);

    this->hashTable->insert(std::pair<std::string, HashItem*>(std::string(key), item));
}

HashItem *HashTable::get(char *key) {
    std::map<std::string, HashItem*>::const_iterator it = this->hashTable->find(std::string(key));

    if(it == this->hashTable->end()) return nullptr;

    return it->second;
}

char *HashTable::getHItemType(HashItem *item) {
    if(!item) return nullptr;
    return item->getType();
}

void *HashTable::getHItemValue(HashItem *item) {
    if(!item) return nullptr;
    return item->getValue();
}

