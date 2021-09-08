// https://leetcode-cn.com/problems/er-wei-shu-zu-zhong-de-cha-zhao-lcof/
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }

        int rows = matrix.size();
        int columns = matrix[0].size();

        int i = 0;
        int j = columns - 1;
        while (i < rows && j >= 0) {
            if (matrix[i][j] == target) { //从右上角开始比较
                return true;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return false;
    }
};