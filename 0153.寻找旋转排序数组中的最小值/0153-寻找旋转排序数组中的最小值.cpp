// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = 0;

        while (left < right) {
            mid = left + (right - left) / 2;
            //mid 的值如果比 right 的值大，说明最小值在 mid 的右边，所以移动left
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            //中间的值如果比最右边的值小，说明最小值在mid的左边，所以移动right
            } else if (nums[mid] < nums[right]) {
                right = mid; // 这里不是mid - 1，因为mid可能是最小值
            }
        }
        return nums[right];	// 循环结束，left == right，最小值输出left或right均可 
    }
};