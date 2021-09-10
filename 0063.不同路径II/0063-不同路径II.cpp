https://leetcode-cn.com/problems/unique-paths-ii/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        // 表示从坐标(0,0) 到坐标 (i, j) 的路径总数
        vector<int> path(n);

        path[0] = (obstacleGrid[0][0] == 0);  // [0][0]位置是否有障碍物
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                
                if (obstacleGrid[i][j] == 1) {
                    path[j] = 0; // 有障碍物：没有路径
                    continue;   
                }

                if (j-1 >= 0 && obstacleGrid[i][j-1] == 0) {
                    path[j] += path[j-1];  // 无障碍物：dp[j] = dp[j] + dp[j - 1]
                }
            }
        }

        return path.back();
    }
};