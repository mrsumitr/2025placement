#Q1 94. Binary Tree Inorder Traversal
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
    void inOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> ans;
       inOrder(root,ans);
       return ans; 
    }
};
//M-2 iterative method
  class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* curr = root;

        while (curr != nullptr || !s.empty()) {
            while (curr != nullptr) {
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            ans.push_back(curr->val);
            curr = curr->right;
        }

        return ans;
    }
};
#Q2 104. Maximum Depth of Binary Tree
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
    void inOrder(TreeNode* root,vector<int> &ans){
        if(root==NULL){
            return;
        }
        inOrder(root->left,ans);
        ans.push_back(root->val);
        inOrder(root->right,ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {  
    
       vector<int> ans;
       inOrder(root,ans);    
       return ans;     
    }
};
#Q3 102. Binary Tree Level Order Traversal
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
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> ans;
    if(root==NULL) return ans;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n=q.size();
        vector<int> level;
        for(int i=0; i<n; i++){
            TreeNode* node=q.front();
            q.pop();
            
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
            level.push_back(node->val);
        }
        ans.push_back(level);
        
    }
    return ans;
    }
};
#Q4 543. Diameter of Binary Tree
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
    void maxL(TreeNode* root, int &depth,int cas){
        if(root==NULL){
            return;
        }
        cas=cas+1;
        depth=max(depth,cas);
        maxL(root->left,depth,cas);
        maxL(root->right,depth,cas); 
        
    }
    void maxR(TreeNode* root, int &depth,int cas){
        if(root==NULL){
            return;
        }
        cas=cas+1;
        depth=max(depth,cas);
        maxR(root->left,depth,cas);
        maxR(root->right,depth,cas); 

    }
    void traverse(TreeNode* root,int &ans){
        if(root==NULL){
            return;
        }
        int left=0;
        int right=0;
        int cas=0;
        maxR(root->right,right,cas);
        maxL(root->left,left,cas);
        ans=max(right+left,ans);
        traverse(root->left,ans);
        traverse(root->right,ans);
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root->left==NULL && root->right==NULL){
            return 0;
        }
       int ans=0;
       traverse(root,ans);
       return ans;
     
        
    }
};
