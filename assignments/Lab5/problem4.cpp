class MinStack {
private:
    stack<int> st1, st2;
public:
    MinStack() {
        while(st1.empty()==false) st1.pop();
        while(st2.empty()==false) st2.pop();
    }
    
    void push(int val) {
        st1.push(val);
        if(st2.empty()==true or st2.top()>=val) st2.push(val);
    }
    
    void pop() {
        int temp = st1.top();
        st1.pop();
        if(st2.top()==temp) st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};