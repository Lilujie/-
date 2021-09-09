// https://leetcode-cn.com/problems/partition-list-lcci/
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
    ListNode* partition(ListNode* head, int x) {
        if (!head) return NULL;
        if (!head->next) return head;

        //快慢指针
        ListNode* slow = head, *fast = head;
        int tmp = 0;
        while(fast) {
            if(fast->val < x) {
                tmp = slow->val;
                slow->val = fast->val;
                fast->val = tmp;
                slow = slow->next;                
            }
            fast = fast->next;
        }
        return head;
    }
};