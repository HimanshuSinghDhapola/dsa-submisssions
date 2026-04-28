class MinStack {
public:
    MinStack() {
        
    }
    stack<pair<int, int>> stk;
    
    void push(int val) {
        if(stk.empty()){
            stk.push({val, val});
        }else{
            int currMin = stk.top().second;
            stk.push({val, min(currMin, val)});
        }
    }
    
    void pop() {
        if(!stk.empty()){
            stk.pop();
        }else{
            return;
        }
    }
    
    int top() {
        return stk.empty() ? -1 : stk.top().first; 
    }
    
    int getMin() {
        return stk.top().second;
    }
};
