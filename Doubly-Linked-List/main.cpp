#include "DoublyLinkedList.h"
#include <iostream>

using namespace std;
void test(){
    DoublyLinkedList dll;
    
    dll.push(1);
    dll.push(2);
    dll.push(3);
    
    DoublyLinkedList dllCopy = dll;
    
    dllCopy.push(4);
    dllCopy.remove(1);
    dllCopy.remove(0);
    dllCopy.insert(25, 1);
    
    dllCopy.print();
}

int main(){
    test();
    
    return 0;
}