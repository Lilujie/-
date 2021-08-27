class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp_max(nums.size(), 0);
        vector<int> dp_min(nums.size(), 0);

        dp_max[0] = nums[0];
        dp_min[0] = nums[0];
        int maxAns = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            dp_max[i] = max({nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]});
            dp_min[i] = min({nums[i], dp_max[i - 1] * nums[i], dp_min[i - 1] * nums[i]});
            maxAns = max({maxAns, dp_max[i], dp_min[i]});
        }

        return maxAns;

    }
};