#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

struct Node{
        int data;
        Node* next;
        Node* prev;
};

class DoublyLinkedList{
    public:
    //Constructor
    DoublyLinkedList();
    
    //Part 3 - The Final Touches
    DoublyLinkedList(const DoublyLinkedList& otherDLL);
    DoublyLinkedList operator=(const DoublyLinkedList& otherDLL);
    ~DoublyLinkedList();
    
    
    // Part 1 - The Essentials
    void push(int data);
    void pop();
    int size() const;
    void print() const;
    int& at(int idx);
    //void prevTest();
    
    // Part 2 - Linked Listrs Specialty Functions
    void insert(int data, int pos);
    void remove(int pos);
    
    //Extra
    Node* getHead() const;
    Node* getTail() const;
    
    private:
    Node* head;
    Node* tail;
    
};


#endif