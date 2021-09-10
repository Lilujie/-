https://leetcode-cn.com/problems/reverse-words-in-a-string/
class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for(int left = 0; left < n; left++) {
            if(s[left] != ' ') { //等于空格，left++；把每个单词前面多余的空格去掉
                if (idx != 0)  s[idx++] = ' '; // 人为地加一个空格

                int right = left;
            
                while(right < n && s[right] != ' ') {
                    s[idx++] = s[right++]; // 重新规整s，不包含多余的空格
                }
                reverse(s.begin() + idx - (right -left), s.begin() + idx);
                left = right;
            }
        }
        s.erase(s.begin() + idx, s.end());  // 删掉最后的空格
        return s;
    }
};