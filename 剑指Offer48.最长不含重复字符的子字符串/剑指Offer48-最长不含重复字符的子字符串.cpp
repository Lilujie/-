//@@@ https://leetcode-cn.com/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, res = 0;
        unordered_map<char, int> window; // 哈希 + 滑动窗口

        while (r < s.size()) {
            int t = s[r];
            r++;
            window[t]++;

            while (window[t] > 1) {
                int c = s[l];
                l++;
                window[c]--;
            }
            res = max(res, r - l);
        }
        return res;
    }
};