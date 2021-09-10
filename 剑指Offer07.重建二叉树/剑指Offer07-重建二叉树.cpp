https://leetcode-cn.com/problems/zhong-jian-er-cha-shu-lcof/
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd, 
                        vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd) {
            return nullptr;
        }

        TreeNode* root = new TreeNode(preorder[preStart]);
        int index = -1;
        for (int i = inStart; i <= inEnd; i++) {
            if (inorder[i] == root->val) {
                index = i;
                break;
            }
        }

        int diff = index - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + diff, inorder, inStart, index - 1);
        root->right = buildTree(preorder, preStart + diff + 1, preEnd, inorder, index + 1, inEnd);
        return root;                    
    } 
};