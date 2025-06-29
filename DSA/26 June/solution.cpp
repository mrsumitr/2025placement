#Q1 Palindrome Linked List
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
    ListNode* prev=NULL;
    ListNode* curr=head;
    while(curr!=NULL){
        ListNode* next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;

    }
    head=prev;
    return head;
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next != NULL){
            fast=fast->next;
            if(fast->next != NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    bool compareList(ListNode* head1, ListNode* head2){
        while(head2 != NULL){
            if(head1->val != head2->val){
                return false;
            }
            else{
                head1=head1->next;
                head2=head2->next;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        //break into two halves
        ListNode* midNode=middleNode(head);
        ListNode* head2=midNode->next;
        midNode->next=NULL;
        //reverse second half
        ListNode* prev=NULL;
        ListNode* curr=head2;
        head2=reverseList(curr);

        bool ans=compareList(head,head2);
        return ans;
    }
};
#Q2 Rotate List
class Solution {
private:
    int countNode(ListNode* head){
        int count = 0;
        while(head != nullptr){
            count++;
            head = head->next;
        }
        return count;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        

        int n = countNode(head);
        if (n==0){
            return nullptr;
        }
        k = k % n;
        if (!head || !head->next || k == 0) return head;
        // Find the (n - k)th node
        int stepsToNewHead = n - k;
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (stepsToNewHead--) {
            prev = curr;
            curr = curr->next;
        }

        // prev is new tail, curr is new head
        prev->next = nullptr;

        ListNode* temp = curr;
        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = head;
        return curr;
    }
};
#Q3 Magical String
class Solution {
public:
    int magicalString(int n) {
        if (n <= 0) return 0;
        if (n <= 3) return 1;

        vector<int> magic = {1, 2, 2};
        int res = 1; // already one '1' in first 3
        int i = 2;   // pointer to current group
        int num = 1; // next number to insert

        while (magic.size() < n) {
            int count = magic[i];
            for (int j = 0; j < count; ++j) {
                magic.push_back(num);
                if (num == 1 && magic.size() <= n)
                    res++;
            }
            num = 3 - num; // toggle between 1 and 2
            i++;
        }

        return res;
    }
};

