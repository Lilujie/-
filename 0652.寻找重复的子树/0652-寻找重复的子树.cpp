https://leetcode-cn.com/problems/find-duplicate-subtrees/
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
private:
    unordered_map<string, int> hash_map;
    vector<TreeNode*> res;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return res;
    }

    string traverse(TreeNode* root) {
        if (root == nullptr) return "";

        string left = traverse(root->left);
        string right = traverse(root->right);

        string ans = left + "," + right + "," + to_string(root->val);

        if (hash_map[ans] == 1) { //如果该 key 不存在，C++ 会自动创建key，并把 map[key] 赋值为 0。
            res.emplace_back(root);
        }

        hash_map[ans]++;

        return ans;

    }
};