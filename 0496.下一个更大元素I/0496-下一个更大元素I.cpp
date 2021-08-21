class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        /*
        先对 nums2 中的每一个元素，求出它的右边第一个更大的元素；
        将上一步的对应关系放入哈希表（HashMap）中；
        再遍历数组 nums1，根据哈希表找出答案。 
        */
        unordered_map<int, int> res; 
        stack<int> s;
        // 先处理nums2；倒着往栈里放，所以栈里面放的都是当前元素后面的元素
        for (int i = nums2.size() - 1; i >= 0; i--) {
            // 判定个子高矮
            while (!s.empty() && s.top() <= nums2[i]) {
                // 矮个起开，把排在我后面比我矮的踢出局
                s.pop();
            }
            // nums2[i] 身后的 下一个更大元素
            res[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> ans;    // 存放答案数组
        for(int i = 0; i < nums1.size(); ++i) {
            ans.push_back(res[nums1[i]]);
        }
        return ans;

    }
};