https://leetcode-cn.com/problems/longest-common-prefix/
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        sort(strs.begin(), strs.end());

        string front = strs.front();
        string back = strs.back();

        int minSize = min(front.size(), back.size());
        int i = 0;
        for(; i < minSize && front[i] == back[i]; i++);
        return front.substr(0, i);
    }
};