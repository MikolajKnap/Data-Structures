#ifndef LIB_LINKED_LIST
#define LIB_LINKED_LIST
#include <iostream>
class Node{
private:
    Node* next;
    Node* prev;
    int value;
public:
    Node(int value, Node* prev, Node* next);

    /**
    Getter next
    */
    Node* getNext();

    /**
    Setter next
    @param temp Node to set as next
    */
    void setNext(Node* temp);

    /**
    Getter prev
    */
    Node* getPrev();

    /**
    Setter next
    @param temp Node to set as prev
    */
    void setPrev(Node* temp);

    /**
    Getter value
    */
    int getValue();

    /**
    Setter value
    @param x Int value to set
    */
    void setValue(int x);
};

class DoubleLinkedList{
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoubleLinkedList();
    int getSize();
    bool isEmpty();
    Node* first();
    Node* last();
    Node* search(int x);
    void insert(int x, Node* k);
    void add(int x);
    void del(Node* temp);
    void clear();
    friend std::ostream& operator<<(std::ostream& out, DoubleLinkedList* list);
};

#endif