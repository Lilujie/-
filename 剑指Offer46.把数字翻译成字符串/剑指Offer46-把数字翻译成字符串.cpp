// https://leetcode-cn.com/problems/ba-shu-zi-fan-yi-cheng-zi-fu-chuan-lcof/
class Solution {
public:
    int translateNum(int num) {
        string str = to_string(num);
        int p = 0, q = 0, r = 1;
        for(int i = 0; i < str.size(); i++) {
            p = q;
            q = r;
            r = q;
            if(i == 0) continue;

            string pre = str.substr(i-1, 2);
            if(pre >= "10" && pre <= "25") r += p;
        }
        return r;
    }
};