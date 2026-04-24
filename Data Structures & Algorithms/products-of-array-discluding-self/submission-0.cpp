class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size=nums.size();
        vector<int> ans;
        vector<int> rtl(size, 1), ltr(size, 1);
        for(int i=1; i<size; i++){
            ltr[i] = ltr[i-1] * nums[i-1];
        }
        for(int i=size-2; i>=0; i--){
            rtl[i] = rtl[i+1] * nums[i+1];
        }
        for(int i=0; i<size; i++){
            int product = ltr[i] * rtl[i];
            ans.push_back(product);
        }
        return ans;
    }
};
