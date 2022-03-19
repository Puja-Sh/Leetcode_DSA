class FreqStack {
public:
    unordered_map<int, int> freq;
    unordered_map<int, stack<int>> group_stack; // maintain recent and max frequeny element
    int max_freq = 0;
    
    FreqStack() {
        
    }
    
    void push(int val) {
        
        freq[val]++;        // maintaining the freq
        
        max_freq = max(max_freq, freq[val]);    // store maximum frequency 
        
        group_stack[freq[val]].push(val);       // group elements of same freq in the stack
    }
    
    int pop() {
        int top_max_freq = group_stack[max_freq].top(); // find the max occured element
        
        group_stack[max_freq].pop();        // now delete it from there
        
        freq[top_max_freq]--;   //decrement frequency in freq map
        
        if(group_stack[max_freq].size() == 0) max_freq--;   // if size of stack = 0 i.e no other element with max_freq is present 
        
        return top_max_freq;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */