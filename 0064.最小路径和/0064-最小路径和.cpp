https://leetcode-cn.com/problems/minimum-path-sum/
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        // for(int i = 0; i < grid.size(); i++) {
        //     for(int j = 0; j < grid[0].size(); j++) {
        //         if(i == 0 && j == 0) continue;

        //         int tp = 1e9;
        //         if(i > 0) tp = min(tp, grid[i-1][j]);
        //         if(j > 0) tp = min(tp, grid[i][j-1]);
        //         grid[i][j] += tp;
        //     }
        // }

        // return grid[grid.size()-1][grid[0].size()-1];

       if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int rows = grid.size(), columns = grid[0].size();
        auto dp = vector < vector <int> > (rows, vector <int> (columns));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < rows; i++) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for (int j = 1; j < columns; j++) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < columns; j++) {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rows - 1][columns - 1];
    }
};