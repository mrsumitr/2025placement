#Q1 Design Queue using Arrays
#include <iostream>
using namespace std;

class Queue {
private:
    int size = 10;
    int q[10]; 
    int currSize = 0;
    int start = -1;
    int end = -1;

public:
    void enqueue(int x) {
        if (currSize == size) {
            cout << "Queue is full!" << endl;
            return;
        }

        if (currSize == 0) {
            start = 0;
            end = 0;
        } else {
            end = (end + 1) % size;
        }

        q[end] = x;
        currSize++;
    }

    void dequeue() {
        if (currSize == 0) {
            cout << "Queue is empty!" << endl;
            return;
        }

        if (currSize == 1) {
            start = -1;
            end = -1;
        } else {
            start = (start + 1) % size;
        }

        currSize--;
    }

    int front() {
        if (currSize == 0) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        return q[start];
    }

    bool isEmpty() {
        return currSize == 0;
    }

    int getSize() {
        return currSize;
    }


};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;
    cout << "Size: " << q.getSize() << endl;
    cout << "Is empty: " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
#Q2 Next Greater Element I
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            int pos=-1;
            bool found=false;
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    pos=j;
                    break;
                }
            }
            for(int k=pos; k<nums2.size(); k++){
                if(nums2[k]>nums2[pos]){
                    ans.push_back(nums2[k]);
                    found=true;
                    break;
                }
            }
            if(!found){
            ans.push_back(-1);
            }
        }
        return ans;
    }
};
#Q3 Next Greater Element II
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            nums.push_back(nums[i]);
        }
        vector<int> ans;
        for(int i=0; i<n; i++){
            bool found=false;
            for(int j=i+1; j<nums.size(); j++){
                if(nums[j]>nums[i]){
                    ans.push_back(nums[j]);
                    found=true;
                    break;
                }
            }
            if(!found){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
#Q4 Odd Even Linked List
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even; 

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead; 
        return head;
    }
};
