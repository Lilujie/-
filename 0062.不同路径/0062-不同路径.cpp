https://leetcode-cn.com/problems/unique-paths/
class Solution {
public:
    int uniquePaths(int m, int n) {
        // dp[i][j] = dp[i-1][j] + dp[i][j-1];
        vector<int> dp(n, 0);
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j){
                dp[j] = (i > 0 && j >0 ) ? dp[j] = dp[j-1] + dp[j] : 1;
            }
        }
        return dp[n-1];
    }
};