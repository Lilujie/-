// https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        // dp[i][j] 表示 s[i..j] 是否是回文串
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        // 先枚举子串长度
        for (int l = 0; l < n; ++l) {//注意，l和i不要反了,i是左边界，j是右边界，l是子串长度
            for (int i = 0; i + l < n; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1; // 长度为1的串都是回文串
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);  // 长度为2的串，如果两个字母相等，则为回文串
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                if (dp[i][j] && l + 1 > ans.size()) {
                    ans = s.substr(i, l + 1);
                }
            }
        }
        return ans;
    }
};