https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window;

        int l = 0, r = 0, res = 0;
        while (r < s.size()) {
            int t = s[r];
            window[t]++;
            r++;

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