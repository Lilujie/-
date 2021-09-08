// https://leetcode-cn.com/problems/merge-sorted-array/
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1, p2 = n - 1, p = m + n - 1;
        while (p1 >= 0 && p2 >= 0) {
            nums1[p--] = nums1[p1] < nums2[p2] ? nums2[p2--] : nums1[p1--];
        }

        //可能p1为0了，p2还不为0
        for (int i = 0; i <= p2; i++) {
            nums1[i] = nums2[i];
        }
    }
};