https://leetcode-cn.com/problems/trapping-rain-water/
class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() < 2) return 0;

        int size = height.size();
        int ans = 0;

        //动态规划法

        // vector<int> leftMax(size);
        // vector<int> rightMax(size);

        // leftMax[0] = height[0];
        // for (int i=1; i < size; i++) {
        //     leftMax[i] = max(leftMax[i-1], height[i]);
        // } 

        // rightMax[size-1] = height[size-1];
        // for (int i = size-2; i >= 0; i--) {
        //     rightMax[i] = max(height[i], rightMax[i+1]);
        // }

        // for (int i=1; i < size-1; i++) {
        //     ans += min(leftMax[i], rightMax[i]) - height[i];
        // }

        // return ans;

        //双指针法
        int leftMax = 0;
        int rightMax = 0;
        int left = 0, right = size-1;

        while(left < right) {
            if (height[left] < height[right]) {
                height[left] > leftMax ? leftMax = height[left] : ans += leftMax - height[left];
                left++;
            } else {
                 height[right] > rightMax ? rightMax = height[right] : ans += rightMax - height[right];
                 right--;
            }        
        }
        return ans;
        //暴力法
        
        // for(int i = 0; i < size; i++) {
        //     int leftMax = 0, rightMax = 0;
        //     for(int j = 0; j <= i; j++) {
        //         leftMax = max(leftMax, height[j]);
        //     }
        //      for(int j = i; j < size; j++) {
        //         rightMax = max(rightMax, height[j]);
        //     }
        //     ans += min(leftMax, rightMax) - height[i];
        // }
        // return ans;
    }
};