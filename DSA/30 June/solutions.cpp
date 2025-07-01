1. Design Stack using Arrays
○ The data structure should contain functions like top, push, pop and peep.
○ peep() function allows the user inspect values at any position in a stack

#include<bits/stdc++.h>
using namespace std;
#include <iostream>
class Stack{
private:
    int top=-1;
    int st[10];
    
public:
    void push(int x){
    if(top>=9){
        cout<<"There is no space"<<endl;
        return;
    }
    top+=1;
    st[top]=x;
    
}
void pop(){
    if(top==-1){
        cout<<"There is no element"<<endl;
        return;
    } 
    
        top--;
    }

int size(){
    return top+1;
}
int getTop(){
    if(top==-1){
        cout<<"There is no element"<<endl;
        return -1;
    }

        return st[top];
    
}

int peep(int position) {
        if (position <= 0 || position > top + 1) {
            cout << "Invalid position" << endl;
            return -1;
        }
        return st[top - position + 1];
    }
};

int main() {
  
    Stack s; 
    s.push(10);
    s.push(20);
    s.push(40);
    s.push(30);
    s.push(80);
    s.push(90);
    cout << "Top element: " << s.getTop() << endl;
    s.pop();
    cout << "Stack size: " << s.size() << endl;
    cout<<s.getTop()<<endl;
    cout<<s.peep(1)<<endl;
    
    return 0;
    
 
}

#Q2 valid parentheses

class Solution {
public:
    bool isValid(string s) {
      stack<char> st;
      int n=s.length();
      for(int i=0; i<n; i++){
        if(s[i]=='(' || s[i]=='{' || s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty()){
                return false;
            }
            char top=st.top();
            if(s[i]==')' && top=='(' || s[i]=='}' && top=='{' || s[i]==']' && top=='[' ){
                st.pop();
            }
            else{
                return false;
            }
        }
      } 
      return st.empty(); 
    }
};

#Q3 Swapping Nodes
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* first = head;
        ListNode* second = head;
        ListNode* temp = head;
        
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }
        
        int last = n - k + 1;  // 
        
        for (int i = 1; i < k; i++) first = first->next;
        
        
        for (int i = 1; i < last; i++) second = second->next;
        swap(first->val, second->val);
        
        return head;
    }
};

