#include "HashTable.h"

#include <iostream>

HashTable::HashTable() {
    this->hashTable = new std::map<char*, HashItem*>();
}

void HashTable::insert(char *key, char *type, void *value) {
    /* Chave já existe */
    if(this->hashTable->find(key) != this->hashTable->end()) {
        HashItem *it = get(key);

        it->redefineValues(type, value);

        return;
    }

    HashItem *item = new HashItem(type, value);

    this->hashTable->insert(std::pair<char*, HashItem*>(key, item));
}

HashItem *HashTable::get(char *key) {
    std::map<char*, HashItem*>::const_iterator it = this->hashTable->find(key);

    if(it == this->hashTable->end()) return nullptr;

    return it->second;
}

char *HashTable::getHItemType(HashItem *item) {
    return item->getType();
}

void *HashTable::getHItemValue(HashItem *item) {
    return item->getValue();
}

