#ifndef LIB_STACK
#define LIB_STACK

class Element{
private:
    Element* next;
    int value;
public:
    /**
    Element constructor
    @param next Pointer to the next element
    @param value The value of the element
    */
    Element(Element* next, int value);

    /**
    Value getter
    @return Returns value of Element
    */
    int getValue();

    /**
    Next setter
    @param next Element to be set as next
    */
    void setNext(Element* next);

    /**
    Next getter
    @return Returns next Element
    */
    Element* getNext();
};


class Stack{
private:
    Element* topp;
public:
    // Constructor for Stack class.
    Stack();

    /**
    Checks if the stack is empty
    @return True if the stack is empty
    */
    bool isEmpty();

    /**
    Pushes a new element
    @param x The value for new element to push
    */
    void push(int x);

    // Removes the top element from the stack.
    void pop();

    // Removes all elements from the stack.
    void clear();

    /**
    Gets the top element
    @return Returns pointer to top of the stack if not empty
    */
    Element* top();
};

#endif