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
    TreeNode* prev;
    bool isValidBST(TreeNode* root) {
        // 方法一： 使用辅助函数，增加函数参数列表，在参数中携带额外信息，将这种约束传递给子树的所有节点，这也是二叉树算法的一个小技巧
        return isValidBST(root, nullptr, nullptr);
        //方法二：
        if(!root) return true;

        //访问左子树
        if (!isValidBST(root->left))  return false;

        //访问当前节点：如果当前节点小于等于中序遍历的前一个节点直接返回false。
        if (prev != nullptr && prev->val >= root->val)  return false;
        prev = root;

        //访问右子树
        if (!isValidBST(root->right))  return false;

        return true;
    }

    bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == nullptr) return true; //. 这里不是return false

        if (min != nullptr && root->val <= min->val) return false;
        if (max != nullptr && root->val >= max->val) return false;

        return isValidBST(root->left, min, root) && isValidBST(root->right, root, max);  // 注意这里的返回，写成&&的关系
    }


};