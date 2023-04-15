#ifndef LIB_HASH_H
#define LIB_HASH_H

class HashTable{
private:
    int capacity;
    int size;
    int *t;

public:
    
    HashTable(int c);
    bool empty();
    bool full();


    int hashFunction(int x);

    int insert(int x);

    void del(int x);

    int search(int x);

};

#endif