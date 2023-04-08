#include "lib_bst.h"
#include <iostream>
#include <exception>

Node::Node(int value, Node* left, Node* right, Node* parent){
    this->left = left;
    this->right = right;
    this->parent = parent;
    this->value = value;
}

Node* Node::getLeft(){
    return this->left;
}

void Node::setLeft(Node* temp){
    this->left = temp;
}

Node* Node::getRight(){
    return this->right;
}

void Node::setRight(Node* temp){
    this->right = temp;
}

Node* Node::getParent(){
    return this->parent;
}

void Node::setParent(Node* temp){
    this->parent = temp;
}

int Node::getValue(){
    return this->value;
}

void Node::setValue(int value){
    this->value = value;
}

BST::BST(){
    this->root = nullptr;
}

bool BST::isEmpty(Node* n){
    return n == nullptr;
}

bool BST::leaf(Node* n){
    if(n == nullptr) throw std::runtime_error("Node can't be null");
    if(n->getLeft() == nullptr && n->getRight() == nullptr) return true;
    else return false;
}

Node* BST::left(Node* n){
    if(n == nullptr) throw std::runtime_error("Node can't be null");
    return n->getLeft();
}

Node* BST::right(Node* n){
    if(n == nullptr) throw std::runtime_error("Node can't be null");
    return n->getRight();
}

Node* BST::parent(Node* n){
    if(n == nullptr) throw std::runtime_error("Node can't be null");
    return n->getParent();
}

int BST::retrieve(Node *n){
    if(n == nullptr) throw std::runtime_error("Node can't be null");
    return n->getValue();
}

void BST::preorder(Node* n){
    if(!isEmpty(n)){
        // some operation
        preorder(left(n));
        preorder(right(n));
    }
}

void BST::inorder(Node* n){
    if(!isEmpty(n)){
        inorder(left(n));
        // some operation
        inorder(right(n));
    }
}

void BST::postorder(Node* n){
    if(!isEmpty(n)){
        postorder(left(n));
        postorder(right(n));
        // some operation
    }
}

int BST::size(Node* n){
    if(isEmpty(n)) return 0;
    else{
        return (1 + size(left(n)) + size(right(n)));
    }
}

int BST::height(Node* n){
    if(isEmpty(n)) return -1;
    else{
        return (1 + std::max(height(left(n)),height(right(n))));
    }
}

void BST::clear(Node* n){
    if(!isEmpty(n)){
        clear(left(n));
        clear(right(n));
        delete n;
    }
}



Node* BST::search(int x){
    Node* temp = root;
    while(!isEmpty(temp) && retrieve(temp) != x){
        if(retrieve(temp) > x) temp = left(temp);
        else temp = right(temp);
    }
    return temp;
}

Node* BST::minimum(Node* n){
    if(isEmpty(n)) return nullptr;
    Node* temp = n;
    while(!isEmpty(left(temp))){
        temp = left(temp);
    }
    return temp;
}

Node* BST::maximum(Node* n){
    if(isEmpty(n)) return nullptr;
    Node* temp = n;
    while(!isEmpty(right(temp))){
        temp = right(temp);
    }
    return temp;
}

Node* BST::successor(Node* n){
    if(isEmpty(n)) return nullptr;
    else if(!isEmpty(right(n))) return minimum(right(n));
    else{
        Node* p = parent(n);
        while(!isEmpty(p) && n == right(p)){
            n = p;
            p = parent(p);
        }
        return p;
    }
}

Node* BST::predecessor(Node* n){
    if(isEmpty(n)) return nullptr;
    else if(!isEmpty(left(n))) return maximum(left(n));
    else{
        Node* p = parent(n);
        while(!isEmpty(p) && n == left(p)){
            n = p;
            p = parent(p);
        }
        return p;
    }
}

void BST::insert(int x){
    Node* temp = root;
    if(isEmpty(temp)){
        Node* newNode = new Node(x,nullptr,nullptr,nullptr);
        root = newNode;
    }
    else{
        while(1){
            if(retrieve(temp) > x){
                if(!isEmpty(left(temp)))
                    temp = left(temp);
                else{
                    Node* newNode = new Node(x,nullptr,nullptr,temp);
                    temp->setLeft(newNode);
                    break;
                }
            }
            if(retrieve(temp) < x){
                if(!isEmpty(right(temp)))
                    temp = right(temp);
                else{
                    Node* newNode = new Node(x,nullptr,nullptr,temp);
                    temp->setRight(newNode);
                    break;
                }
            }
        }
    }
}

void BST::del(Node* n){
    if(isEmpty(n)) return;
    else if(leaf(n)){
        if(isEmpty(n->getParent())){
            root = nullptr;
        }
        else{
            Node* p = n->getParent();
            if(n == p->getLeft()) p->setLeft(nullptr);
            else p->setRight(nullptr);
        }
        delete n;
        return;
    }
    else if (!isEmpty(n->getLeft()) && !isEmpty(n->getRight())){
        Node* s = successor(n);
        n->setValue(s->getValue());
        del(s);
    }
    else{
        Node* s;
        if(!isEmpty(n->getLeft())) s = n->getLeft();
        else s = n->getRight();
        Node* p = n->getParent();
        if(isEmpty(p)){
            root = s;
        }
        else{
            if(n == p->getLeft()) p->setLeft(s);
            else p->setRight(s);
        }
        s->setParent(p);
        delete n;
    }
}


