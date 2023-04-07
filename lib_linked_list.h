#ifndef LIB_LINKED_LIST
#define LIB_LINKED_LIST
#include <iostream>

class Node{
private:
    Node* next;
    Node* prev;
    int value;
public:
    /**
    Constructor for class node
    @param value Value of created node
    @param prev Pointer to the previous node
    @param next Pointer to the next node
    */
    Node(int value, Node* prev, Node* next);

    /**
    Getter for the next node
    @return Pointer to the next node
    */
    Node* getNext();

    /**
    Setter for the next node
    @param temp Pointer to the node to be set as the next node
    */
    void setNext(Node* temp);

    /**
    Getter for the prev node
    @return Pointer to the prev node
    */
    Node* getPrev();

    /**
    Setter for the prev node
    @param temp Pointer to the node to be set as the prev node
    */
    void setPrev(Node* temp);

    /**
    Getter for the node value
    @return Value (int) of node
    */
    int getValue();

    /**
    Setter for the node value
    @param x Value (int) to be set as value of the node
    */
    void setValue(int x);
};

class DoubleLinkedList{
private:
    Node* head;
    Node* tail;
    int size;
public:
    /**
    Constructor for the class DoubleLinkedList
    */
    DoubleLinkedList();

    /**
    Getter for the size of the list
    @return Size of the list (int)
    */
    int getSize();

    /**
    Checks if the list is empty
    @return True if the list is empty, false if not
    */
    bool isEmpty();

    /**
    Getter for the head node in the list
    @return Pointer to the head node in the list
    */
    Node* first();

    /**
    Getter for the tail node in the list
    @return Pointer to the tail node in the list
    */
    Node* last();

    /**
    Searches for node with the x value
    @param x Value (int) to search for
    @return Pointer to the node with the x value, or nullptr if not found
    */
    Node* search(int x);

    /**
    Inserts a new node with the x value before the specified node
    @param x Value (int) to be in the new node
    @param k Pointer to the node before which the new node will be inserted
    */
    void insert(int x, Node* k);

    /**
    Add a new node with x value on the end of the list
    @param x Value (int) to be in the new node
    */
    void add(int x);

    /**
    Deletes the specified node
    @param temp Pointer to the node to be deleted
    */
    void del(Node* temp);

    /**
    Clears list
    */
    void clear();

    /**
    Overloaded operator to print all nodes of the list
    */
    friend std::ostream& operator<<(std::ostream& out, DoubleLinkedList* list);
};

#endif