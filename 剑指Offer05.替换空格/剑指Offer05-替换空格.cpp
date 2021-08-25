class Solution {
public:
    string replaceSpace(string s) {
        string array;   //存储结果
        
        for(auto &c : s){   //遍历原字符串
            if(c == ' '){
                array.push_back('%');
                array.push_back('2');
                array.push_back('0');
            }
            else{
                array.push_back(c);
            }
        }
        return array;
    }
};