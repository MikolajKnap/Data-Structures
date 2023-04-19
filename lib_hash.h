#ifndef LIB_HASH_H
#define LIB_HASH_H

class HashTable{
private:
    int capacity;
    int size;
    int *t;

public:
    /**
    Constructor of the HashTable class
    @param c integer value representing the capacity of the hash table
    Initializes the capacity, size and t (array to store the values) of the hash table
    Sets all the values of t to 0
    */
    HashTable(int c);

    /**
    Checks if the hash table is empty
    @return true if the size of the hash table is 0, false otherwise
    */
    bool empty();

    /**
    Checks if the hash table is full
    @return true if the size of the hash table is equal to its capacity, false otherwise
    */
    bool full();

    /**
    Calculates the hash value of the given integer using modulo operation with the capacity
    @param x integer value to calculate the hash value for
    @return the hash value of the given integer
    */
    int hashFunction(int x);

    /**
    Inserts an integer value into the hash table
    @param x integer value to insert into the hash table
    @return the number of collisions that occurred during the insertion
    */
    int insert(int x);
    
    /**
    Deletes the given integer value from the hash table
    @param x integer value to delete from the hash table
    */
    void del(int x);

    /**
    Searches for the given integer value in the hash table
    @param x integer value to search for in the hash table
    @return the number of collisions that occurred during the search, or -1 if the value was not found
    */
    int search(int x);

};

#endif