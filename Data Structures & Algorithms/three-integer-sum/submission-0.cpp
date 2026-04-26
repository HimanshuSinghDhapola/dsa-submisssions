class Solution {
private:
    void twoSum(vector<int>& nums, int target, int start, int end, vector<vector<int>>& ans){
        while(start<end){
            int sum = nums[start]+nums[end];
            if(sum>target){
                end--;
            }else if(sum<target){
                start++;
            }else{
                while(nums[start]==nums[start+1])start++;
                while(nums[end] == nums[end-1]) end--;

                ans.push_back({-target, nums[start], nums[end]});
                start++;
                end--;
            }
        }
    }
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int size = nums.size();
        
        sort(nums.begin(), nums.end());
        for(int i=0; i<size-2; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -nums[i];
            twoSum(nums, target, i+1, size-1, ans);
        }
        return ans;
    }
};
