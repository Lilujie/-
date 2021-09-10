https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        //dp[i][0] 第i天不持有股票的最大利润
        //dp[i][1] 第i天持有股票的最大利润
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] - fee);
            dp[i][1] = max(dp[i-1][0] - prices[i], dp[i-1][1]);
        }

        return dp[n-1][0];

    }
};