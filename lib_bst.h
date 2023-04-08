#ifndef LIB_BST
#define LIB_BST

class Node{
private:
    Node* left;
    Node* right;
    Node* parent;
    int value;
public:
    /**
    Constructor for Node class
    @param value Value to bet set in node
    @param left Pointer to the left child node
    @param right Pointer to the right child node
    @param parent Pointer to the parent node
    */
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
    /**
    Constructor for BST
    */
    BST();

    /**
    Checks if node/tree is empty
    @param n Node/rootOfTree to check
    @return Returns true if the node/tree is empty
    */
    bool isEmpty(Node* n);

    /**
    Checks if node is leaf
    @param n Node to check
    @return Returns true if the node is a leaf
    */
    bool leaf(Node* n);

    /**
    Gets left child of a node
    @param n Node to get the left child from
    @return Returns pointer to the left child
    */
    Node* left(Node* n);

    /**
    Gets right child of a node
    @param n Node to get the right child from
    @return Returns pointer to the right child
    */
    Node* right(Node* n);

    /**
    Gets parent of a node
    @param n Node to get the parent from
    @return Returns pointer to the parent
    */
    Node* parent(Node* n);

    /**
    Retrieves the value of a node
    @param n Node to retrieve the value from
    @return Returns the value of the node
    */
    int retrieve(Node* n);

    /**
    Traverse the tree in preorder
    @param n Root node of the subtree to traverse
    */
    void preorder(Node* n);

    /**
    Traverse the tree in inorder
    @param n Root node of the subtree to traverse
    */
    void inorder(Node* n);

    /**
    Traverse the tree in postorder
    @param n Root node of the subtree to traverse
    */
    void postorder(Node* n);

    /**
    Get the size of a tree/subtree
    @param n Root node of the tree/subtree
    @return Returns the size of the tree/subtree
     */
    int size(Node* n);

    /**
    Get the height of a tree/subtree
    @param n Root node of the tree/subtree
    @return Returns the height of the tree/subtree
    */
    int height(Node* n);

    /**
    Clears a tree/subtree
    @param n Root node of the tree/subtree
    */
    void clear(Node* n);

    /**
    Search for a node with a given value
    @param x The value to search for
    @return Returns pointer to the node with the value or nullptr if not found
    */
    Node* search(int x);

    /**
    Get the node with the minimum value in the tree/subtree
    @param n Root node of the tree/subtree
    @return Returns pointer to the node with the minimum value in the tree/subtree or nullptr if the tree/subtree is empty
    */
    Node* minimum(Node* n);

    /**
    Get the node with the maximum value in the tree/subtree
    @param n Root node of the tree/subtree
    @return Returns pointer to the node with the maximum value in the tree/subtree or nullptr if the tree/subtree is empty
    */
    Node* maximum(Node* n);

    /**
    Get the successor of a given node
    @param n Node to get the successor of
    @return Pointer to the successor node or nullptr if there is no successor
    */
    Node* successor(Node* n);

    /**
    Get the predecessor of a given node
    @param n Node to get the predecessor of
    @return Pointer to the predecessor node or nullptr if there is no predecessor
    */
    Node* predecessor(Node* n);

    /**
    Insert a node with a given value 
    @param x Value of the node to insert
    */
    void insert(int x);

    /**
    Delete a given node from the tree
    @param n Node to delete
    */
    void del(Node* n);
};


#endif