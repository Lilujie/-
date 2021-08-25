class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s1;
        int i = 0;
        
        for (auto& num : pushed) {
             s1.push(num);
            
             while (!s1.empty() && s1.top() == popped[i]) {
                 s1.pop();
                 i++;
             }

        }

        return s1.empty();
    }
};