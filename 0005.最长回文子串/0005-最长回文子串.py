https://leetcode-cn.com/problems/longest-palindromic-substring/
class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        # dp[i][j] 表示 s[i..j] 是否是回文串
        dp = [[False] * n for _ in range(n)]
        ans = ""

        for l in range(n):
            for i in range(n):
                j = i + l
                if j >= n:
                    break
                if l == 0:
                    dp[i][j] = True
                elif l == 1:
                    dp[i][j] = (s[i] == s[j])
                else:
                    dp[i][j] = (s[i] == s[j] and dp[i + 1][j - 1])
                if dp[i][j] and l + 1 > len(ans):
                    ans = s[i: j + 1]  # 这里不要写成j了。因为切片取元素不包含最后一个
        return ans