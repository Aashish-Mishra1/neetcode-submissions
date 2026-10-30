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

    void dfs(TreeNode* root,int& goodNodes,int maxi){

        if(!root) return;

        maxi = max(maxi,root->val);
        if(root->val>=maxi){
            goodNodes++;
        }

        dfs(root->left,goodNodes,maxi);
        dfs(root->right,goodNodes,maxi);
    }
    int goodNodes(TreeNode* root) {
        
        int maxi = INT_MIN;
        int goodNodes = 0;
        dfs(root,goodNodes,maxi);
        return goodNodes;
    }
};
