#Q1 236. Lowest Common Ancestor of a Binary Tree
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left && right) return root;
        return (left != nullptr) ? left : right;
    }
};
#Q2 2385. Amount of Time for Binary Tree to Be Infected
class Solution {
private:
    // Standard height function
    int height(TreeNode* root) {
        if (!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }

    // Modified to return distance if found, else -1
    int isthere(TreeNode* root, int start, int& maxTime) {
        if (!root) return -1;

        if (root->val == start) {
            // Return height of this subtree (spread time downwards)
            maxTime = max(maxTime, height(root) - 1);
            return 0;  // distance from start to itself
        }

        int left = isthere(root->left, start, maxTime);
        if (left != -1) {
            // Infection can go to the right subtree
            maxTime = max(maxTime, left + 1 + height(root->right));
            return left + 1;
        }

        int right = isthere(root->right, start, maxTime);
        if (right != -1) {
            // Infection can go to the left subtree
            maxTime = max(maxTime, right + 1 + height(root->left));
            return right + 1;
        }

        return -1;  // Not found in this subtree
    }

public:
    int amountOfTime(TreeNode* root, int start) {
        int maxTime = 0;
        isthere(root, start, maxTime);
        return maxTime;
    }
};

#Q3 222. Count Complete Tree Nodes
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
    void cnt(TreeNode* root, int &count){
        if(root==NULL){
            return;
        }
        count++;
        cnt(root->left,count);
        cnt(root->right,count);
    }
public:
    int countNodes(TreeNode* root) {
        int count=0;
        cnt(root,count);
        return count;
    }
};
#Q4 98. Validate Binary Search Tree
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
    void inorder(TreeNode* root, vector<int> &check){
        if(!root) return;
        inorder(root->left,check);
        check.push_back(root->val);
        inorder(root->right,check);
    }
public:

    bool isValidBST(TreeNode* root) {
       vector<int> check;
       inorder(root,check);
       for(int i=0; i<check.size()-1; i++){
        if(check[i]>=check[i+1]){
            return false;
        }
        
       }
       return true;
    }

};
