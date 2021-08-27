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
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0, head);

        ListNode* pre = dummy;
        ListNode* cur = head;

        while (cur->val != val) {
            pre = cur;
            cur = cur->next;
        }
        if (cur != nullptr) {
            pre->next = cur->next;
        }
        return dummy->next;
    }
};