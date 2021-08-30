class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n-1)); // 逻辑运算符的短路性质来表达递归出口
        return n;

    }
};