#include "lib_stack.h"

Element::Element(Element* next, int value){
    this->next = next;
    this->value = value;
}

int Element::getValue(){
    return this->value; 
}

void Element::setNext(Element* next){
    this->next = next;
}

Element* Element::getNext(){
    return this->next;
}

Stack::Stack(){
    this->topp = nullptr;
}
bool Stack::isEmpty(){
    return topp==nullptr;
}
void Stack::push(int x){
    Element* temp = new Element(topp,x);
    topp = temp;
}
void Stack::pop(){
    if(!isEmpty()){
        Element* temp = topp;
        topp = topp->getNext();
        delete temp;
    }
}
void Stack::clear(){
    while(!isEmpty()){
        pop();
    }
}
Element* Stack::top(){
    if(!isEmpty()) return topp;
}