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
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        return (A && B ) && (subTree(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }

    bool subTree(TreeNode* A, TreeNode* B) { // 判断每一个节点都相等
        if (B == nullptr) return true;

        if (A == nullptr || A->val != B->val) return false;

        return subTree(A->left, B->left) && subTree(A->right, B->right);
    }
};