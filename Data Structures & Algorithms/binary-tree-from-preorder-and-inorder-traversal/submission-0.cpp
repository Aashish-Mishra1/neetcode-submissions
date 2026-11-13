class Solution {
public:
    TreeNode* dfs(int ind, int left, int right, vector<int>& preorder, vector<int>& inorder) {
        if (ind >= preorder.size() || left > right) {
            return nullptr;
        }

        TreeNode* node = new TreeNode(preorder[ind]);
        
        for (int i = left; i <= right; i++) {
            if (inorder[i] == preorder[ind]) {
                // Number of nodes in the left subtree is (i - left)
                int leftSubtreeSize = i - left;
                
                node->left = dfs(ind + 1, left, i - 1, preorder, inorder);
                node->right = dfs(ind + 1 + leftSubtreeSize, i + 1, right, preorder, inorder);
                break; // Stop searching once the root is found
            }
        }
        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return dfs(0, 0, preorder.size() - 1, preorder, inorder);
    }
};
