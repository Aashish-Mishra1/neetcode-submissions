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
    bool helper(TreeNode* node,int leftLimit,int rightLimit){

        if(!node) return true;

        if(node->val<=leftLimit || node->val>=rightLimit) return false;
        return helper(node->left,leftLimit,node->val) && helper(node->right,node->val,rightLimit);
    }
    bool isValidBST(TreeNode* root) {
        
        return helper(root,INT_MIN,INT_MAX);
    }
};
