https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        vector<int> res(2, -1);
        // 找左边界
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                right = mid - 1;
            }
        }
        
        if (left >= nums.size() || nums[left] != target)
            return res;
        else
            res[0] = left;

        // 找右边界
        left = 0, right = nums.size() - 1;
         while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] == target) {
                left = mid + 1;
            }
        }
        
        if (right < 0 || nums[right] != target)  return {-1, -1};
       
        res[1] = right;
        return res;

    }
};