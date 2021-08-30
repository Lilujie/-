class Solution {
public:
    int numWays(int n) {
        int p = 1, q = 1, r = 2;
        for (int i = 0; i < n; i++) {
            r = (p + q) % 1000000007;
            p = q;
            q = r;
        }

        return p;

    }
};