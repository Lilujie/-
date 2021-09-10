https://leetcode-cn.com/problems/how-many-numbers-are-smaller-than-the-current-number/
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> count(101,0);
        int len = nums.size();
        vector<int> result;

        for (int i = 0; i < len; i++) {
            count[nums[i]]++;
        }

        for (int i = 1; i <= 100; i++) {
            count[i] += count[i-1];
        }

        for (int i = 0; i < len; i++) {
            result.push_back(nums[i] == 0 ? 0 : count[nums[i]-1]);
        }
        return result;
    }
};