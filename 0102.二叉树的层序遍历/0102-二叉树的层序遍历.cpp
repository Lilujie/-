https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 层序遍历需要借助队列实现：首先将根结点入队,然后开始执行循环:结点出队、访问该结点、其左右儿子入队
 // 该题要求按层输出，所以比原始的层序遍历多了20、21、22三行。
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {       
        vector<vector<int>> result;
        if(root == nullptr) return result;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            result.push_back(vector<int>());
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if(node) result.back().push_back(node->val);
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return result;

        }
};