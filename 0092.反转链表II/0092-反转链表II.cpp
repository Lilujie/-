// https://leetcode-cn.com/problems/reverse-linked-list-ii/
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }

        // 把head->next的索引是为1，反转区间应该是【m-1， n-1】
        head->next = reverseBetween(head->next, left - 1, right - 1);

        return head; 

    }

    ListNode* reverseN(ListNode* head, int right) {
        if (right == 1) {
            successor = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, right - 1);
        head->next->next = head;
        head->next = successor;
        return last;
    }

private:
    ListNode* successor = nullptr;
};