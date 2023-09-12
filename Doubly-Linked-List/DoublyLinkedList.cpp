#include "DoublyLinkedList.h"
#include <iostream>

//Constructor
DoublyLinkedList::DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
}

//Part 3 - The Final Touches

//Copy Constructor, good lord this hurt my head
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& otherDLL){
    //If other list is empty then make the new list empty
    if(otherDLL.head == nullptr){
        head = nullptr;
    }else{
        //New List that points to input list
        Node* list1 = otherDLL.head;
        head = tail = new Node;
        head->prev = nullptr;
        head->data = list1->data;
        
        list1 = list1->next;
        if(list1 == nullptr){
            head->next = nullptr;
        }else{
            //List 2 tracks the list being created
            Node* list2 = head;
            
            while(list1 != nullptr){
                list2->next = new Node;
                list2->next->prev = list2;
                list2 = list2->next;
                
                list2->data = list1->data;
                list1 = list1->next;
            }
            list2->next = nullptr;
            tail = list2;
        }
    }
}
//Operator= overload
DoublyLinkedList DoublyLinkedList::operator=(const DoublyLinkedList& otherDLL){
    //Checks if the lists are already equal
    if(&otherDLL != this){
        //Checks to see if new list is empty
        if(head != nullptr){
            Node* currPos = head;
            while(currPos != tail->next){
                Node* temp = currPos;
                currPos = currPos->next;
                delete temp;
            }
            head = nullptr;
            tail = nullptr;
        }
        //Checks to see if input list is empty, if so set new list empty
        if(otherDLL.head == nullptr){
            head = nullptr;
        }else{
            //List1 that points to input list
            Node* list1 = otherDLL.head;
            head = new Node;
            tail = new Node;
            //New List Head = Input List head
            head->data = list1->data;
            list1 = list1->next;
            //Checks to see if the input List's next node has a value
            if(list1 == nullptr){
                head->next = nullptr;
            }else{
                Node* list2 = head;
                //Runs through list1 and assigns each node in list2 to list1 nodes data
                while(list1 != nullptr){
                    list2->next = new Node;
                    list2->next->prev = list2;
                    list2 = list2->next;
                    
                    list2->data = list1->data;
                    list1 = list1->next;
                }
                //Sets tail to be at the end
                list2->next = nullptr;
                tail = list2;
                }
            }
        }
    //Return the list
    return *this;
}
//Deconstructor
DoublyLinkedList::~DoublyLinkedList(){
    std::cout << "The Deconstructor has finished calling..." << std::endl;
    while(head != tail->next){
        delete head;
        head = head->next;
    }
}


//Part 1 - The Essentials
void DoublyLinkedList::push(int data){
    if(head == nullptr){
        head = new Node;
        head->data = data;
        head->next = nullptr;
        tail = head;
    }else{
        tail->next = new Node;
        tail->next->data = data;
        tail->next->prev = tail;
        tail = tail->next;
    }
}
void DoublyLinkedList::pop(){
    if(head == tail){
        return;
    }
    if(head->next == tail){
        delete tail;
        tail = head;
        return;
    }
    Node* temp = tail->prev;
    delete tail;
    tail = temp;
}
int DoublyLinkedList::size() const{
    int numElements = 0;
    Node* currPos = head;
    while(currPos != tail->next){
        numElements++;
        currPos = currPos->next;
    }
    return numElements;
    
}
void DoublyLinkedList::print() const{
    Node* currPos = head;
    while(currPos != tail->next){
        std::cout<< currPos->data << " ";
        currPos = currPos->next;
    }
    std::cout << std::endl;
}
int& DoublyLinkedList::at(int idx){
    Node* currPos = head;
    int startPos = 0;
    while(startPos < idx){
        startPos++;
        currPos = currPos->next;
    }
    return currPos->data;
}
/*
//Test if Nodes remember previous nodes
void DoublyLinkedList::prevTest(){
    Node* currPos = head;
    while(currPos->next != tail->next){
        std::cout << (currPos->next->prev)->data << std::endl;
        currPos = currPos->next;
    }
    std::cout << currPos->data << std::endl;
}
*/



//Part 2 - Linked Lists Specialty Functions
void DoublyLinkedList::insert(int data, int pos){
    //if position at head 
    if(pos < 1){
        Node* temp = new Node;
        temp->data = data;
        temp->next = head;
        temp->prev = nullptr;
        temp->next->prev=temp;
        head = temp;
    }else if(pos >= size()){
        Node* temp = new Node;
        temp->data = data;
        temp->prev = tail;
        temp->next = nullptr;
        temp->prev->next = temp;
        tail = temp;
    }else{
        Node* currPos = head;
        int idx = 0;
        //Loop till one before position
        while(idx < (pos - 1)){
            idx++;
            currPos = currPos->next;
        }
        Node* temp = currPos->next;
        currPos->next = new Node;
        currPos->next->data = data;
        currPos->next->next = temp;
        currPos->next->prev = currPos;
    }
}
void DoublyLinkedList::remove(int pos){
    //Empty List
    if(head == tail){
        return;
    }
    //Remove last element
    if(pos == size() - 1){
        pop();
        return;
    }if(pos == 0){
        Node* temp = head->next;
        delete head;
        head = temp;
        return;
    }else{
        Node* currPos = head;
        int idx = 0;
        while(idx < (pos-1)){
            idx++;
            currPos = currPos->next;
        }
        Node* temp = currPos->next;
        currPos->next = currPos->next->next;
        currPos->next->prev = currPos->prev;
        delete temp;
    }
}


//Extra
Node* DoublyLinkedList::getHead() const{
    return head;
}
Node* DoublyLinkedList::getTail() const{
    return tail;
}
