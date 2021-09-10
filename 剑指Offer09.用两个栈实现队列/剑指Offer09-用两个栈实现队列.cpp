https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/
class CQueue {
private:
    stack<int> s1;
    stack<int> s2;
public:
    CQueue() {

    }
    void in2out() {
          if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }   
        }
    }
    void appendTail(int value) {
    //队列：先进先出，栈：先进后出
        s1.push(value);
    }
    
    int deleteHead() {
        in2out();// 将栈最下面的元素倒到最上面，然后弹出
        if (s2.empty()) {
            return -1;
        }
        int val = s2.top();
        s2.pop();
        return val;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */