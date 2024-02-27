#include "HashItem.h"
#include "Matrix.h"

#include <string>

HashItem::HashItem(char *type, void *value) {
    this->type = type;
    this->value = value;
}

char *HashItem::getType() {
    return this->type;
}

void *HashItem::getValue() {
    return this->value;
}

void HashItem::redefineValues(char *type, void *value) {
    std::string str = "matrix";

    if(str.compare(this->getType()) == 0) {
        Matrix *m = (Matrix *) this->value;

        delete m;
    } else {
        free(this->value);
    }

    free(this->type);

    this->type = type;
    this->value = value;
}
