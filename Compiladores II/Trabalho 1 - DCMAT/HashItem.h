#ifndef HASHITEM_H
#define HASHITEM_H

class HashItem {
    public:
        HashItem(char *type, void *value);

        char *getType();

        void *getValue();

        void redefineValues(char *type, void *value);
    
    private:
        char *type;
        void *value;
};

#endif