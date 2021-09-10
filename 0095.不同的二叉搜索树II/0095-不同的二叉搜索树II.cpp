//@@@ https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};

        return generateTrees(1, n);
    }

    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> res;

        // 枚举所有可能的根节点
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1); // 递归左边
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);  // 递归右边

            // 从左边选择一个树，右边选择一个树，和根节点组成一整棵树
            for (auto& leftTree : leftTrees) {   
                for (auto& rightTree : rightTrees) {
                    TreeNode* curTree = new TreeNode(i);
                    curTree->left = leftTree;
                    curTree->right = rightTree;
                    res.push_back(curTree);
                }
            }
        }

        return res;
    }

};