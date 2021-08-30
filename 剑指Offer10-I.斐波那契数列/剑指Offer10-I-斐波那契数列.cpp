class Solution {
public:
    int fib(int n) {
        int p = 0,  q = 1, r;
        for (int i = 0; i < n; i++) {
            r = (p + q) % 1000000007;
            p = q;
            q = r;
        }

        return p; // important!

    }
};