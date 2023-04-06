#include "lib_linked_list.h"

class Node{
private:
    Node* next;
    Node* prev;
    int value;
public:
    Node(int value, Node* prev, Node* next){
        this->value = value;
        this->prev = prev;
        this->next = next;
    }
    Node* getNext(){
        return this->next;
    }
    void setNext(Node* temp){
        this->next = temp;
    }
    Node* getPrev(){
        return this->prev;
    }
    void setPrev(Node* temp){
        this->prev = temp;
    }
    int getValue(){
        return this->value;
    }
    void setValue(int x){
        this->value = x;
    }
};

class DoubleLinkedList{
private:
    Node* head;
    Node* tail;
    int size;
public:
    DoubleLinkedList(){
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    int size(){
        return this->size;
    }
    bool isEmpty(){
        if(head == nullptr) return true;
        else return false;
    }
    Node* first(){
        return this->head;
    }
    Node* last(){
        return this->tail;
    }
    Node* search(int x){
        if(!isEmpty()){
            Node* temp = head;
            while(temp != nullptr){
                if(temp->getValue() == x) return temp;
                temp = temp->getNext();
            }
            return nullptr;
        }
    }
    void insert(int x, Node* k){
        if(isEmpty()){
            Node* temp = new Node(x,nullptr,nullptr);
            head = temp;
            tail = temp;
        }
        else if(k == first()){
            Node* temp = new Node(x,nullptr,head);
            head = temp;
        }
        else{
            Node* temp = new Node(x,k->getPrev(),k);
            k->getPrev()->setNext(temp);
            k->setPrev(temp);
        }
        //Maybe one more
    }
    void del();
    void clear();
};