class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_set<string> validOperations = {"+", "-", "*", "/"};
        stack<long long> stk;
        for(auto &it: tokens){
            if(it.length() == 1 && validOperations.count(it)>0){
                int first = stk.top();
                stk.pop();
                int second = stk.top();
                stk.pop();
                switch(it[0]){ // because switch only works with integral types like int, char etc. not string
                    case '+':
                        stk.push(second+first);
                        break;
                    case '-':
                        stk.push(second-first);
                        break;
                    case '*':
                        stk.push(second*first);
                        break;
                    case '/':
                        stk.push(second/first);
                        break;
                }
            }else{
                int num = stoi(it);
                stk.push(num);
            }
        }
        return stk.top();
    }
};
