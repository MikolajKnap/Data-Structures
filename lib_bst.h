#ifndef LIB_BST
#define LIB_BST

class Node{
private:
    Node* left;
    Node* right;
    Node* parent;
    int value;
public:
    Node(int value, Node* left, Node* right, Node* parent);
    Node* getLeft();
    void setLeft(Node* temp);
    Node* getRight();
    void setRight(Node* temp);
    Node* getParent();
    void setParent(Node* temp);
    int getValue();
    void setValue(int value);
};

class BST{
private:
    Node* root;
public:
    BST();
    bool isEmpty(Node* n);
    bool leaf(Node* n);
    Node* left(Node* n);
    Node* right(Node* n);
    Node* parent(Node* n);
    int retrieve(Node *n);
    void preorder(Node* n);
    void inorder(Node* n);
    void postorder(Node* n);
    int size(Node* n);
    int height(Node* n);
    void clear(Node* n);

    Node* search(Node* n, int x);
    Node* minimum(Node* n);
    Node* maximum(Node* n);
    Node* successor(Node* n);
    Node* predecessor(Node* n);
};


#endif