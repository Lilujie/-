https://leetcode-cn.com/problems/two-sum/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_map; // 元素值，和它的索引
        
        for (int i = 0; i < nums.size(); i++) { // O(N)
            auto it = hash_map.find(target - nums[i]);
            if (it != hash_map.end()) {
                return {it->second, i};
            }
            hash_map[nums[i]] = i;
        }

        return {};
    }
};