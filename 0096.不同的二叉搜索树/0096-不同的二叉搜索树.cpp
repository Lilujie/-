//@@@ https://leetcode-cn.com/problems/unique-binary-search-trees/
class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1, 0);

        // dp[i]代表有i个节点时，能组成多少种二叉搜索树。
        dp[0] = 1; // 0个节点时可组成1种二叉搜索树，空树也是二叉搜索树
        dp[1] = 1; // 1个节点时可组成1种二叉搜索树

        // 当节点数为2，3，... ,n时分别有多少种不同的二叉搜索树
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= i; j++) { // 节点数为i时，左子树的个数为j-1，右子树的个数为i-j
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};