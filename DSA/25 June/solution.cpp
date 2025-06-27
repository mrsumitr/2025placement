#Q1 reverse a LL
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
public:
    ListNode* reverseList(ListNode* head) {
    stack <int> st;
    ListNode* temp=head;
    while(temp!=NULL){
        st.push(temp->val);
        temp=temp->next;
    }  

    temp=head;
    while(temp!=NULL){
        temp->val=st.top();
        st.pop();
        temp=temp->next;
    }

    return head;
    }
};

#Q2 cyclic check
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next==NULL){
            return false;
        }

        unordered_map<ListNode*,int> mp;

        ListNode* temp=head;
        while(temp!=NULL){
            if(mp.find(temp)!=mp.end()){
                return true;
            }
            mp[temp]++;
            temp=temp->next;

        }
        return false;

    }
};
