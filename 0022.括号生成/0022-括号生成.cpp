https://leetcode-cn.com/problems/generate-parentheses/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(0, 0, n, "", result);
        return result;
    }

    void generate(int left, int right, int n, string s, vector<string> & result) {
        if(left == n && right == n) {
            result.push_back(s);
            return;
        }

        if(left < n) generate(left+1, right, n, s + "(", result);
        if(left > right) generate(left, right + 1, n, s + ")", result);
    }
};