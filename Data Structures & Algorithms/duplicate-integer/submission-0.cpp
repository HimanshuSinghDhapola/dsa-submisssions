class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> dup;
        for(auto i: nums){
            if(dup.find(i) != dup.end()){
                return true;
            }else{
                dup.insert(i);
            }
        }
        return false;
    }
};