https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2) return l1 ? l1:l2;

        ListNode* aptr = l1;
        ListNode* bptr = l2;
        ListNode head;
        ListNode* point = &head;

        while(aptr && bptr) {
            if(aptr->val < bptr->val) {
                point->next = aptr;
                aptr = aptr->next;
            } else {
                point->next = bptr;
                bptr = bptr->next;
            }

            point = point->next;
        }
        point->next = aptr ? aptr : bptr;
        return head.next;
    }
};