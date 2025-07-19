#Q1 199. Binary Tree Right Side View
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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(root==NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
         
         while(!q.empty()){
        int size=q.size();
        for(int i=0; i<size; i++){
            TreeNode* node=q.front();
            q.pop();
            if(i==size-1){
                ans.push_back(node->val);
            }
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
           
        }
        
        }
        return ans;
    }
    
};
#Q2 113. Path Sum II
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
    void path(TreeNode* root, vector<int> dep, vector<vector<int>> &ans, int target,int sum){
        if(!root) return;
        sum+=root->val;
        dep.push_back(root->val);
        if(sum==target){
            if(!root->left && !root->right){
                ans.push_back(dep);
            }
        }
        path(root->left,dep,ans,target,sum);
        path(root->right,dep,ans,target,sum);
        



    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
      vector<vector<int>> ans;
      if(!root) return ans;
      vector<int> dep;
      path(root,dep,ans,targetSum,0);  
      return ans;
    }
};
#Q3 236. Lowest Common Ancestor of a Binary Tree
