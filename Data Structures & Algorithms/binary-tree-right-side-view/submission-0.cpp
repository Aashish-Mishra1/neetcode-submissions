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
    void dfs(TreeNode* root,int height,vector<int>&rightView){

        if(!root) return;
        if(height==rightView.size()){
            rightView.push_back(root->val);
        }

            dfs(root->right,height+1,rightView);
            dfs(root->left,height+1,rightView);

        
    }
    vector<int> rightSideView(TreeNode* root) {

        vector<int> rightView;

        dfs(root,0,rightView);
        return rightView;
        
    }
};
