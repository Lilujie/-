// https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
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
    void flatten(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->left);
        flatten(root->right);

        // 此时，左右子树已经被拉平为一个单链表了
        TreeNode* left = root->left;
        TreeNode* right = root->right;

        // 将左子树作为右子树
        root->left = nullptr;
        root->right = left;

        // 将原先的右子树接到当前右子树的右边
        TreeNode* p = root;

        while(p->right) {
            p = p->right;
        }

        p->right = right;

    }
    
};