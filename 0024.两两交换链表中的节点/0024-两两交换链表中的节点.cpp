https://leetcode-cn.com/problems/swap-nodes-in-pairs/
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
    ListNode* swapPairs(ListNode* head) {
        //第一种：递归写法
        // if(!head || head->next == nullptr) return head;
        // ListNode* tmp = head->next;
        // head->next = swapPairs(tmp->next);        
        // tmp->next = head;
        // return tmp;
        // 第二种：迭代写法
        //头节点可能变化的都会建立哑节点,这样不用判断头节点是否为空
        ListNode* dummy = new ListNode();
        dummy->next = head;

        ListNode* temp = dummy;
        while (temp->next && temp->next->next) {
            ListNode * node1 = temp->next;
            ListNode* node2 = temp->next->next;
            temp->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            temp = temp->next->next;
        }
        return dummy->next;
    }
};