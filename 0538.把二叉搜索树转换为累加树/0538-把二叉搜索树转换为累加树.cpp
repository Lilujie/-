https://leetcode-cn.com/problems/convert-bst-to-greater-tree/
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
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }

    int sum = 0;
    TreeNode* traverse(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);

        return root;
    }
};