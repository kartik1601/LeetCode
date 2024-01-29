class MyQueue {
    stack<int> s1, s2;
public:
    MyQueue() {}
    
    void transfer(stack<int>&f,stack<int>&s){
        while(!f.empty()){
            s.push(f.top());
            f.pop();
        }
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        transfer(s1,s2);
        int x = s2.top(); s2.pop();
        transfer(s2,s1);
        return x;
    }
    
    int peek() {
        transfer(s1,s2);
        int x = s2.top();
        transfer(s2,s1);
        return x;
    }
    
    bool empty() {
        return s1.size()==0;
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