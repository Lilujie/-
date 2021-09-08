// https://leetcode-cn.com/problems/implement-stack-using-queues/
class MyStack {
private:
queue<int> inQueue;
queue<int> outQueue;

public:
    /** Initialize your data structure here. */
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        inQueue.push(x);
        while (!outQueue.empty()) {
            inQueue.push(outQueue.front());
            outQueue.pop();
        }
        swap(inQueue, outQueue);
    }
 
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int x = outQueue.front();
        outQueue.pop();
        return x;
    }
    
    /** Get the top element. */
    int top() {
        return outQueue.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return outQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */