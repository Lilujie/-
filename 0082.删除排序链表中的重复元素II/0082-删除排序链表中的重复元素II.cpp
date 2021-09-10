https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) return nullptr;
    
        ListNode* dummy = new ListNode;
        dummy->next = head;
        
        ListNode* cur = dummy;
        while (cur->next && cur->next->next) { // cur始终指向相同元素的前一个元素
            if (cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while (cur->next && cur->next->val == x) { //如果cur的后面两个元素相同，就从后面的元素开始找第一个不相同的元素，使得cur的next指向第一个不相同的元素
                    cur->next = cur->next->next;
                }
            }
            else {
                cur = cur->next;
            }
        }
        
        return dummy->next;
    }
};