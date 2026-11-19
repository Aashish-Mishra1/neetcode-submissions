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

        if(!root) return {};
        queue<TreeNode*> qu;
        qu.push(root);

        vector<vector<int>>ans;
        while(!qu.empty()){
            int n = qu.size();
            vector<int>temp(n);
            for(int i=0;i<n;i++){
                TreeNode* node = qu.front();
                qu.pop();
                temp[i] = node->val;

                if(node->left){
                    qu.push(node->left);
                }
                if(node->right){
                    qu.push(node->right);
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};
