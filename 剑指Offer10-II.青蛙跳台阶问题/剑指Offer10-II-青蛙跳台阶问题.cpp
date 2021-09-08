// https://leetcode-cn.com/problems/qing-wa-tiao-tai-jie-wen-ti-lcof/
class Solution {
public:
    int numWays(int n) {
         if (n == 0 || n == 1) return 1;

        int p = 1, q = 1, r;
        for (int i = 2; i <= n; i++) {
            r = (p + q) % 1000000007;
            p = q;
            q = r;
        }

        return r;
    }
};