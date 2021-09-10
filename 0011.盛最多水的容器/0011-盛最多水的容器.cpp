https://leetcode-cn.com/problems/container-with-most-water/
class Solution {
public:
    int maxArea(vector<int>& height) {
        // 双指针法
        if(height.size() < 2) return 0;

        int i = 0, j = height.size()-1;
        int max = 0;
        while(i < j) {
            // 两个指针指向的数字中较小值∗指针之间的距离
            int product = (height[i] > height[j] ? height[j] : height[i] ) * (j - i);
            if (product > max) max = product;

            // 移动较小数字的指针
            if (height[i] > height[j])  j--;
            else i++;
        }
       
        return max;
    }
};