// https://leetcode-cn.com/problems/linked-list-cycle/
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr) return false;

        ListNode* slow = head, *fast = head->next;

        while(slow != fast) {
            if(fast == nullptr || fast->next == nullptr) return false;//快指针将到达链表尾部，该链表不为环形链表。
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};