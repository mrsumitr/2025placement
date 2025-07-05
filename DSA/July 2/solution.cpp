#Q1 LC 225. Implement Stack using Queues
class MyStack {

private:
    queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
       q.push(x);
       int n=q.size();
       for(int i=0; i<n-1; i++){
        q.push(q.front());
        q.pop();
       } 
    }
    
    int pop() {
       int val=q.front();
       q.pop();
       return  val;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

#Q2 LC 232. Implement Queue using Stacks
class MyQueue {
private:
    stack<int> s1,s2;
public:

    MyQueue() {
        
    }
    
    void push(int x) {
        while(s1.size()){
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(s2.size()){
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int val=s1.top();
        s1.pop();
        return val;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};
#Q3 LC 150. Evaluate Reverse Polish Notation
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = s.top(); s.pop();
                int a = s.top(); s.pop();
                int result;

                if (token == "+") result = a + b;
                else if (token == "-") result = a - b;
                else if (token == "*") result = a * b;
                else result = a / b;

                s.push(result);
            } else {
                s.push(stoi(token));  
            }
        }

        return s.top();
    }
};

