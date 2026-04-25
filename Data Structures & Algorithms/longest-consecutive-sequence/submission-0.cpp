class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int ans=0;
        for(auto &it: nums){
            st.insert(it);
        }
        for(auto&it: st){
            if(st.find(it-1) != st.end()) continue;
            else{
                int startPoint = it;
                int cnt = 1;
                while(st.find(startPoint+1) != st.end()){
                    cnt++;
                    startPoint++;
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};
