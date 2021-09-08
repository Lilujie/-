// https://leetcode-cn.com/problems/delete-node-in-a-bst/
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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == nullptr) return nullptr;
        if (root->val == key) {
            // 情况 1：A 恰好是末端节点，两个子节点都为空，那么它可以当场去世了。
            // 情况 2：A 只有一个非空子节点，那么它要让这个孩子接替自己的位置。
            if (root->right == nullptr) return root->left;
            if (root->left == nullptr) return root->right;

            // 情况3: A 有两个子节点，麻烦了，为了不破坏 BST 的性质，A 必须找到左子树中最大的那个节点，或者右子树中最小的那个节点来接替自己。
            TreeNode* minNode = getMin(root->right);
            root->val = minNode->val;
            root->right = deleteNode(root->right, minNode->val);

        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }

        return root;

       // 一旦涉及「改」，函数就要返回 TreeNode 类型，并且对递归调用的返回值进行接收。

    }

    TreeNode* getMin(TreeNode* node) {
        while (node->left != nullptr) node = node->left;
        return node;
    }
};