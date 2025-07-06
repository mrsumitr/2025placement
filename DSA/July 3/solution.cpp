#Q1 682. Baseball Game
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        for(auto opn: operations){
            if(opn=="+" || opn=="D" || opn=="C"){
                
                int res=0;
                if(opn=="+"){
                    int b=st.top();
                    st.pop();
                    int a=st.top(); 
                    st.push(b);  
                    res=a+b;
                    st.push(res);
                }
                else if(opn=="D"){
                    int b=st.top();
                    st.push(2*b);
                }
                else{
                    st.pop();
                }
                
            }
            else{
                    st.push(stoi(opn));
                }
            
        
            
        }
        int sum=0;
        while(!st.empty()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
};
#Q2 726. Number of Atoms


#Q3 382. Linked List Random Node
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
    ListNode* head;
public:
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int result = head->val;
        ListNode* curr = head->next;
        int i = 2; // Start from second node

        while (curr) {
            // Generate a random number between 0 and i-1
            if (rand() % i == 0) {
                result = curr->val;
            }
            curr = curr->next;
            i++;
        }

        return result;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
