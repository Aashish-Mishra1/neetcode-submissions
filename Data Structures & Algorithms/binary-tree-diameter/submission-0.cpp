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
    int height(TreeNode* root,int& dia){

        if(root==nullptr) return 0;
        int leftheight = height(root->left,dia);
        int rightheight = height(root->right,dia);

        dia = max(dia,leftheight+rightheight);

        return 1+max(leftheight,rightheight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        
        int x = height(root,dia);
        return dia;

    }
};
