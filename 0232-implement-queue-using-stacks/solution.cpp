class MyQueue {
public:
    stack<int> st;
    stack<int> t;
    MyQueue() {
        
    }
    
    void push(int x) {
        st.push(x);
    }
    
    int pop() {
        while(st.size()>0){
            t.push(st.top());
            st.pop();
        }
        int x=t.top();
        t.pop();
        while(t.size()>0){
            st.push(t.top());
            t.pop();
        }
        return x;
    }
    
    int peek() {
        while(st.size()>0){
            t.push(st.top());
            st.pop();
        }
        int x=t.top();
        while(t.size()>0){
            st.push(t.top());
            t.pop();
        }
        return x;
    }
    
    bool empty() {
        return st.size()==0;
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
