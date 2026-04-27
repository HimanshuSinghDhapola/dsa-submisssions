// Space complexity O(N); Time complexity O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int size=height.size();
        vector<int>leftMax(size, INT_MIN), rightMax(size, INT_MIN);
        int maxi=INT_MIN;
        for(int i=0; i<size; i++){
            maxi=max(maxi, height[i]);
            leftMax[i]=maxi;
        }
        maxi = INT_MIN;
        for(int i=size-1; i>=0; i--){
            maxi=max(maxi, height[i]);
            rightMax[i]=maxi;
        }
        int ans=0;
        for(int i=0; i<size; i++){
            ans+=min(leftMax[i], rightMax[i]) - height[i];
        }
        return ans;
    }
};
