/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return isSymmetric(root->left, root->right);
        }
        return true;
    }

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == nullptr && right == nullptr) return true;
        if (left == nullptr || right == nullptr || left->val != right->val) return false;
                 
        return isSymmetric(left->left, right->right) and isSymmetric(left->right, right->left);
    }
};