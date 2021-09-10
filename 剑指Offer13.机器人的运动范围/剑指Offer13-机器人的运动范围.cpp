//@@@ https://leetcode-cn.com/problems/ji-qi-ren-de-yun-dong-fan-wei-lcof/
class Solution {
public:
    int movingCount(int m, int n, int k) {
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // 和剑指 Offer 12. 矩阵中的路径不相同的是，这里递归下探的是i和j，所以没有for循环
        return dfs(0, 0, k, m, n, visited);
    }
private:
    int dfs(int i, int j, int k, int m, int n, vector<vector<bool>>&  visited) {
        if (i >= m || j >= n || sum(i, j) > k || visited[i][j] == true) return 0;

        visited[i][j] = true;

        return 1 + dfs(i + 1, j, k, m, n, visited) + dfs(i, j + 1, k, m, n, visited);
    }

    int sum(int i, int j) {
        int sumi = 0;
        for (; i > 0; i /= 10) {
            sumi += i % 10; // 个位
        }

        for (; j > 0; j /= 10) {
            sumi += j % 10; // 个位
        }

        return sumi;
    }

};