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



