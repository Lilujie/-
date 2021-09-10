https://leetcode-cn.com/problems/implement-queue-using-stacks/
class MyQueue {
private:
stack<int> inStack;
stack<int> outStack;

public:
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        inStack.push(x);

    }
    void in2out() {
        if (outStack.empty()) {
            while (!inStack.empty()) {
                outStack.push(inStack.top());
                inStack.pop();
            }
        }
    }
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        in2out();

        int x = outStack.top();
        outStack.pop();
        return x;
    }
    
    /** Get the front element. */
    int peek() {
        in2out();
        int x = outStack.top();
        return x;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return inStack.empty() && outStack.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */