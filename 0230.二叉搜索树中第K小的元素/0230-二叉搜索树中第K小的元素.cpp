// https://leetcode-cn.com/problems/kth-smallest-element-in-a-bst/
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
    int rank = 0;
    int res = 0;
    int kthSmallest(TreeNode* root, int k) {
        // BST 中序遍历就是升序排序结果
        if (root == nullptr) {
            return 0;
        }

        kthSmallest(root->left, k);
        rank++;
        if (rank == k) {
            res = root->val; // 因为是递归，堆栈一层层pop，所以这里需要把找到的值用res保存起来，以便后面return时返回
            return res;
        }
        kthSmallest(root->right, k);
        return res;
    }
};