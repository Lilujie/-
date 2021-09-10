//@@@ https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-zui-jin-gong-gong-zu-xian-lcof/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // if(!root || root == p|| root == q) return root;
        // TreeNode* l = lowestCommonAncestor(root->left, p, q);
        // TreeNode* r = lowestCommonAncestor(root->right, p, q);

        // // l、r 非空时，说明 p、q 分居 root 的两侧，root 就是 LCA
        // // l、r 任一为空，说明 LCA 位于另一子树或其祖先中
        // return l?(r?root:l):r;

        // 二分查找

        TreeNode* ancessor = root;
        while (true) {
            if (p->val < ancessor->val && q->val < ancessor->val) {
                ancessor = ancessor->left;
            } else if (p->val > ancessor->val && q->val > ancessor->val) {
                ancessor = ancessor->right;
            } else {
                break;
            }
        }
        return ancessor;
    }
};