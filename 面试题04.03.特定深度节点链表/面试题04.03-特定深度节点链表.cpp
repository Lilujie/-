https://leetcode-cn.com/problems/list-of-depth-lcci/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        if (tree == nullptr) return {};

        queue<TreeNode*> q;
        vector<ListNode*> ans;
        q.push(tree);

        while (!q.empty()) {
            int size = q.size();
            ListNode head, *p = &head;
            for (int i = 0; i < size; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                p->next = new ListNode(tmp->val);
                p = p->next;
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            }
            ans.push_back(head.next);
        }
        return ans;

    }
};