class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto &it: s){
            if(it == '[' || it == '(' || it == '{'){
                stk.push(it);
            }
            else{
                if(stk.empty()) return false;
                char top = stk.top();
                if((it == ']' && top == '[') || 
                  (it == ')' && top == '(') || 
                  (it == '}' && top == '{')){
                    stk.pop();
                }else{
                    return false;
                }
            }
        }
        return stk.empty();
    }
};
