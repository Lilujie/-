https://leetcode-cn.com/problems/merge-k-sorted-lists/
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
    ListNode* merge2Lists(ListNode* a, ListNode* b)
{
    if (!a || !b) {
        return a ? a : b;
    }

    ListNode head, *point = &head, *aptr = a, *bptr = b;

    while (aptr && bptr) {
        if (aptr->val < bptr->val) {
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

ListNode* merge(vector<ListNode*> &lists, int left, int right)
{
    if (left > right) {
        return nullptr;
    }

    if (left == right) {
        return lists[left];
    }

    int mid = (left + right) / 2;
    return merge2Lists(merge(lists, left, mid), merge(lists, mid + 1, right));
}

ListNode* mergeKLists(vector<ListNode*> &lists)
{
    //return merge(lists, 0, lists.size() - 1);
    ListNode* ans = nullptr;
    for(size_t i = 0; i < lists.size(); i++) {
        ans = merge2Lists(ans, lists[i]);
    }

    return ans;
}

};