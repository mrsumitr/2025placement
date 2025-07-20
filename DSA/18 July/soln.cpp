#Q1 173. Binary Search Tree Iterator
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;

    void pushAllLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); 
        st.pop();
        if (node->right) {
            pushAllLeft(node->right);
        }
        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};


/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
#Q2 235. Lowest Common Ancestor of a Binary Search Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (p->val < root->val && q->val < root->val)
        return lowestCommonAncestor(root->left, p, q);  
    else if (p->val > root->val && q->val > root->val)
        return lowestCommonAncestor(root->right, p, q); 
    else
        return root;  
}
};

#Q3 653. Two Sum IV - Input is a BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root,vector<int> &data){
        if(root==NULL) return;
        inorder(root->left,data);
        data.push_back(root->val);
        inorder(root->right,data);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        
        vector<int> data;
        inorder(root,data);
    int start=0;
    int end=data.size()-1;
    while(start<end){
        if(data[start]+data[end]==k){
            return true;
        }
        else if(data[start]+data[end]<k){
            start++;
        }
        else{
            end--;
        }
    }
    return false;
    }
};
#Q4 114. Flatten Binary Tree to Linked List
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void preorder(TreeNode* root,queue<TreeNode*> &q){
        if(!root) return;
        q.push(root);
        preorder(root->left,q);
        preorder(root->right,q);
    }
public:
    void flatten(TreeNode* root) {
        queue<TreeNode*> q;
        preorder(root,q);
        if(!q.empty()){
            q.pop();
        }
        TreeNode* temp=root;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            temp->left=NULL;
            temp->right=node;
            temp=temp->right;
        }
    
        

    }
};
