#include "lib_linked_list.h"
#include <iostream>


Node::Node(int value, Node* prev, Node* next){
    this->value = value;
    this->prev = prev;
    this->next = next;
}
Node* Node::getNext(){
    return this->next;
}
void Node::setNext(Node* temp){
    this->next = temp;
}
Node* Node::getPrev(){
    return this->prev;
}
void Node::setPrev(Node* temp){
    this->prev = temp;
}
int Node::getValue(){
    return this->value;
}
void Node::setValue(int x){
    this->value = x;
}

DoubleLinkedList::DoubleLinkedList(){
    head = nullptr;
    tail = nullptr;
    size = 0;
}
int DoubleLinkedList::getSize(){
    return this->size;
}
bool DoubleLinkedList::isEmpty(){
    return head == nullptr;
}
Node* DoubleLinkedList::first(){
    return this->head;
}
Node* DoubleLinkedList::last(){
    return this->tail;
}
Node* DoubleLinkedList::search(int x){
    if(!isEmpty()){
        Node* temp = head;
        while(temp != nullptr){
            if(temp->getValue() == x) return temp;
            temp = temp->getNext();
        }
    }
    return nullptr;

}
void DoubleLinkedList::insert(int x, Node* k){
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
    size++;
}

void DoubleLinkedList::add(int x){
    if(isEmpty()){
        Node* temp = new Node(x, nullptr, nullptr);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(x, tail, nullptr);
        tail->setNext(temp);
        tail = temp;
    }
}

void DoubleLinkedList::del(Node* temp){
    if(temp == nullptr){
        std::cout << "You can't delete node that doesn't exist\n";
        return;
    }
    if(temp == first()){
        head = head->getNext();
        if(head == nullptr){
            tail = nullptr;
            delete temp;
            return;
        }
        head->setPrev(nullptr);
        delete temp;
    }
    else{
        temp->getPrev()->setNext(temp->getNext());
        if(temp->getNext() == nullptr){
            tail = temp->getPrev();
            delete temp;
            return;
        }
        temp->getNext()->setPrev(temp->getPrev());
        delete temp;
    }
    size--;
}
void DoubleLinkedList::clear(){
    Node* temp = head;
    while(temp != nullptr){
        temp = temp->getNext();
        delete head;
        head = temp;
    }
    tail = nullptr;
    size = 0;
}

std::ostream &operator<<(std::ostream &out, DoubleLinkedList *list)
{
    Node* temp = list->head;
    while(temp != nullptr){
        out << temp->getValue() << " ";
        temp = temp->getNext();
    }
    return out;
}
