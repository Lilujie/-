https://leetcode-cn.com/problems/reorder-list/
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
    void reorderList(ListNode* head) {
        if(!head) return;
        deque<ListNode*> q;
        ListNode* tmp = head;
        while (tmp->next) {
            q.push_back(tmp->next);
            tmp = tmp->next;
        }
        tmp = head;
        while (q.size()) {
            tmp->next = q.back();
            q.pop_back();
            tmp = tmp->next;
            if(q.size()) {
                tmp->next = q.front();
                q.pop_front();
                tmp = tmp->next;
            }
        }
        tmp->next = nullptr;  
    }
    
};