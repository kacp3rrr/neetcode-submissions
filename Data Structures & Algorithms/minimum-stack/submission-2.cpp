class MinStack {
private:
    stack<int> st;
    stack<int> min;
public:
    MinStack() {}
    
    void push(int val) {
        st.push(val);
        if (min.empty() || val <= min.top()) min.push(val);
    }
    
    void pop() {
        if (st.top() == min.top()) min.pop();
        st.pop();        
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min.top();
    }
};
