class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> vec(n);
        for(int i=0; i<n; i++){
            vec[i] = {position[i], speed[i]};
        }

        sort(vec.begin(), vec.end(), [](pair<int, int>&a, pair<int, int>&b){
            return a.first > b.first;
        });

        stack<float> stk;

        for(auto it: vec){
            float timeTaken = (float)(target-it.first)/it.second;
            if(stk.empty() || timeTaken>stk.top()){
                stk.push(timeTaken);
            }
        }

        return stk.size();
    }
};
