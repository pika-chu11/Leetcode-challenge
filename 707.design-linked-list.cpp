/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
struct Node
{
    int val;
    Node * next;
};


class MyLinkedList {
    Node * head;
    int length;

public:
    MyLinkedList() : head(nullptr), length(0) {}
    
    int get(int index) {
        if (index >= length || index < 0) {
            return -1;
        }

        Node * walker = head;
        for (int i = 0; i < index; i++) {
            walker = walker->next;
        }
        return walker->val;
    }
    
    void addAtHead(int val) {
        if(head != nullptr){
            Node * node = new Node();
            node->val = val;
            node->next = head;
            head = node;
        }
        else {
            head = new Node();
            head->val = val;
            head->next = nullptr;
        }
        length++;

    }
    
    void addAtTail(int val) {
        Node * walker = head;
        if (head != nullptr) {
            while (walker->next != nullptr)
            {
                walker = walker->next;
            }
            Node * node = new Node();
            node->val = val;
            node->next = nullptr;
            walker->next = node;
            length++;
        }
        else {
            addAtHead(val);
        }
    }
    
    void addAtIndex(int index, int val) {
        if(index > length || index < 0) {
            return;
        }
        if(index == length) {
            addAtTail(val);
        }

        else if (index == 0){
            addAtHead(val);
        }
        else{
            Node * prev = nullptr;
            Node * curr = head;
            for (int i = 0; i < index; i++) {
                prev = curr;
                curr = curr->next;
            }

            Node * node = new Node();
            node->val = val;
            node->next = curr;
            prev->next = node;

            length++;
        }

    }
    
    void deleteAtIndex(int index) {
        if(index >= length) {
            return;
        }

         if (index == 0) {
            Node * temp = head;
            head = head->next;
            delete temp;
        }
        

        Node * prev = nullptr; 
        Node * curr = head;

        for (int i = 0; i < index; i++) {
            prev = curr;
            curr = curr->next;
           
        }
       
        prev->next = curr->next;
        delete curr;
        
        length--;
    }

    int getLength() {
        return length;
    }

};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

#include <iostream>
using namespace std;
int main () {
    MyLinkedList * list = new MyLinkedList();
    
    list->addAtHead(1);
    list->addAtHead(10);
    list->addAtHead(2);
    list->addAtTail(3);
    list->addAtIndex(2, 5);
    list->addAtIndex(5, 7);
    list->addAtIndex(0, 0);
    list->addAtIndex(3, 4);
    cout << "LinkedList: \n";
    for(int i = 0; i < list->getLength(); i++) {
        cout << list->get(i) << " -> ";

    }
    cout << endl;
    cout << "length: " << list->getLength() << endl; 

    
    cout << "Delete" << endl;
    for(int i = 0; i < 8; i++) {
        list->deleteAtIndex(1);
    }
    cout << endl;
    cout << "length: " << list->getLength() << endl; 

    for(int i = 0; i < list->getLength(); i++) {
        cout << list->get(i) << " -> ";

    }
    cout << endl;
    cout << "length: " << list->getLength() << endl; 


}




// @lc code=end

