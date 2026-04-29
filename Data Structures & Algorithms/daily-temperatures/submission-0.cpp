class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int size=temperatures.size();
        vector<int> ans(size, 0);
        stack<int> stk; // used to store index
        for(int i=size-1; i>=0; i--){
            while(!stk.empty() &&  temperatures[stk.top()] <= temperatures[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top() - i;
            }
            stk.push(i);
        }
        return ans;
    }
};
