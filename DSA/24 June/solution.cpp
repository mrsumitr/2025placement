#Q1 1. Design a Singly Linked List and write functions to

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val, Node* next1 = nullptr) {
        data = val;
        next = next1;
    }

    Node() {
        data = 0;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    // Insert at beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val, head);
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }

    // Insert at any index
    void insertAtIndex(int index, int val) {
        if (index == 0) {
            insertAtBeginning(val);
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* newNode = new Node(val, temp->next);
        temp->next = newNode;
    }

    // Delete at beginning
    void deleteAtBeginning() {
        if (head == nullptr) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete at end
    void deleteAtEnd() {
        if (head == nullptr) return;
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while (temp->next->next != nullptr)
            temp = temp->next;

        delete temp->next;
        temp->next = nullptr;
    }

    // Delete at index
    void deleteAtIndex(int index) {
        if (index == 0) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        for (int i = 0; i < index - 1 && temp != nullptr; i++)
            temp = temp->next;

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Index out of bounds\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Delete first occurrence of node with given value
    void deleteByValue(int val) {
        if (head == nullptr) return;

        if (head->data == val) {
            deleteAtBeginning();
            return;
        }

        Node* temp = head;
        while (temp->next != nullptr && temp->next->data != val)
            temp = temp->next;

        if (temp->next == nullptr) {
            cout << "Value not found\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};


int main() {
    LinkedList list;

    // Insert at beginning
    list.insertAtBeginning(10);
    list.insertAtBeginning(20);
    list.display();

    // Insert at end
    list.insertAtEnd(30);
    list.insertAtEnd(40);
    list.display(); 

    // Insert at index
    list.insertAtIndex(2, 99); 
    list.display(); 

    // Delete at beginning
    list.deleteAtBeginning();
    list.display(); 

    // Delete at end
    list.deleteAtEnd();
    list.display(); 

    // Delete at index
    list.deleteAtIndex(1); 
    list.display(); 

    // Delete by value
    list.insertAtEnd(50);
    list.insertAtEnd(60);
    list.display(); 

    list.deleteByValue(30);
    list.display(); 

    list.deleteByValue(100); 
}






#Q2 Delete in a Singly Linked List



/* Link list Node
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    /* Function to delete a node from a linked list */
    Node* deleteNode(Node* head, int x) {
        // code here
        if(head==NULL){
            return NULL;
        }
        int cnt=0;
        Node* temp=head;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
            
        }
        
        if(x==1){
            Node* curr=head;
            head=head->next;
            delete curr;
            return head;
        }
        if(x==cnt){
        Node* curr=head;
        while(curr->next->next!=NULL){
            curr=curr->next;
        }
        delete curr->next;
        curr->next=NULL;
        return head;
        }
        int pos=0;
        Node* curr=head;
        Node* prev=NULL;
        
        while(pos<x){
            if(pos+1==x){
                prev->next=curr->next;
                delete curr;
                break;
            }
            pos++;
            prev=curr;
            curr=curr->next;
  
        }
        return head;
 
    }
};

#Q3 middle Node
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
int count(ListNode* head){
    int cnt=0;
ListNode* temp=head;
while(temp!=nullptr){
    cnt++;
    temp=temp->next;
}
    return  cnt/2;
}
public:
    ListNode* middleNode(ListNode* head) {
        int cnt=count(head);
        ListNode* temp=head;
        while(cnt--){
            temp=temp->next;
        }
        return temp;
    }
};
