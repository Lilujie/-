https://leetcode-cn.com/problems/climbing-stairs/
class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) return 1;

        int p = 1, q = 1, r;
        for (int i = 2; i <= n; i++) {
            r = p + q;
            p = q;
            q = r;
        }

        return r;
    }
};