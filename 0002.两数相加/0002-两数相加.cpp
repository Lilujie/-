//@@@ https://leetcode-cn.com/problems/add-two-numbers/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode head, * pSum = &head;
        int add1 = 0;

        while (l1 || l2) {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            int sum = a + b + add1;
            add1 = sum / 10;
            pSum->next = new ListNode(sum % 10);
            pSum = pSum->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        if (add1 > 0) {
            pSum->next = new ListNode(add1);
        }

        return head.next;
    }
};