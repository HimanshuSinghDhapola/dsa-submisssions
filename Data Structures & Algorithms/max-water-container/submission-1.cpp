// Optimized approach
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=INT_MIN, size=heights.size();
        int start=0, end=size-1;
        while(start<end){
            int minHeight=min(heights[start], heights[end]);
            int trappedWater = minHeight * (end-start);
            ans = max(ans, trappedWater);
            if(heights[start]<heights[end]){
                start++;
            }else{
                end--;
            }
        }
        return ans;
    }
};
