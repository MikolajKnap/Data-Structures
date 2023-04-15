#ifndef LIB_HASH_H
#define LIB_HASH_H

class HashTable{
int capacity;
int size;
int *t;

HashTable(int c);

int hashFunction(int x);

int insert(int x);

void del(int x);

int search(int x);

};

#endif