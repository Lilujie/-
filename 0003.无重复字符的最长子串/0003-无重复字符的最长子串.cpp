class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;
        
        int l = 0,r = 0, res = 0;
        while (r < s.size()) {
            int t = s[r];
            r++;
            // 进行窗口内数据的更新
            window[t]++;
            // 判断左窗口是否需要更新
            while (window[t] > 1) {
                int c = s[l];
                l++;
                // 进行窗口内数据的更新
                window[c]--;
            }
            res = max(res, r - l);// 更新结果
        }
        return res;

    }
};