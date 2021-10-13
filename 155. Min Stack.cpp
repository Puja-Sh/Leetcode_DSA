class MinStack {    
public:
    /** initialize your data structure here. */
   vector<pair <int,int>> stack;  
    
    MinStack() {}
    
    void push(int val) {
        //emplace_back(): it will push the element after the last element without creating constructor
        //back(): it will give last element in the vector
        // Storing the min in second <int,int> of stack so that getMin() will be easier to find
        if(stack.empty()) stack.emplace_back(val, val);
        else stack.emplace_back(val, min(val, stack.back().second));
    }
    
    void pop() {
        stack.pop_back();
    }
    
    int top() {
        return stack.back().first;
    }
    
    int getMin() {
        return stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
