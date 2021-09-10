//@@@ https://leetcode-cn.com/problems/diao-zheng-shu-zu-shun-xu-shi-qi-shu-wei-yu-ou-shu-qian-mian-lcof/
class Solution {
public:
    vector<int> exchange(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;

        // 首尾双指针
        while (l < r) {
            if (nums[l] % 2 == 1) {
                l++;
                continue;
            }

            if (nums[r] % 2 == 0) {
                r--;
                continue;
            }

            swap(nums[l++], nums[r--]);
        }

        return nums;
    }
};