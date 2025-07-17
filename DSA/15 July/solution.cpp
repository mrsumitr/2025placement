#Q1 100. Same Tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
       if(p==NULL && q==NULL) return true;
       if((p==NULL && q!=NULL) ||(p!=NULL && q==NULL)) return false;
       if(p->val!=q->val) return false;
       return isSameTree(p->left,q->left) && isSameTree(p->right,q->right); 
    }
};
#Q2 103. Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    
    vector<vector<int>> ans;
    if(root==NULL){
        return ans;
    }
    queue<TreeNode*> q;
    q.push(root);
    
    while(!q.empty()){
        int size=q.size();
        vector<int> level;
        for(int i=0; i<size; i++){
            TreeNode* node=q.front();
            level.push_back(node->val);
            q.pop();
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);
        }
        if(ans.size()%2==0){
            ans.push_back(level);
        }
        else{
            reverse(level.begin(),level.end());
            ans.push_back(level);
        }
    }
        return ans;
    }
};
#Q3 112. Path Sum
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
    void check(TreeNode* root, int targetSum,int sum, bool &checks){
        if(root==NULL){ 
            return;
        }
        sum=sum+root->val;
        if(root->left==NULL && root->right==NULL){
            if(sum==targetSum){
                checks=true;
                return;
            }
            }
        
        check(root->left,targetSum,sum,checks);
        check(root->right,targetSum,sum,checks);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return false;
        }
        bool checks=false;
        check(root,targetSum,0,checks);
        return checks;
    }
};
#Q4 226. Invert Binary Tree
--M1--
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
    void invert(TreeNode* root){
        if(root==NULL) return;
        TreeNode* left=root->left;
        TreeNode* right=root->right;
        root->right=left;
        root->left=right;
        invert(root->left);
        invert(root->right);
    }
public:
    TreeNode* invertTree(TreeNode* root) {
    
    invert(root);
    return root;
    }
};
