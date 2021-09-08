class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if (n == 0) return -1;
        if (n == 1) return target == nums[0] ? 0 : -1;

        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            
            if (target == nums[mid]) return mid;

            // 根据有序的那个部分确定我们该如何改变二分查找的上下界，
            // 因为我们能够根据有序的那部分判断出 target 在不在这个部分
            if (nums[0] <= nums[mid]) { // 0~mid有序
                if (target >= nums[0] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {  //0~mid 无序，说明另一半有序
                if (target > nums[mid] && target <= nums[n - 1]) {  // 写成target >= nums[mid + 1]报错
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};