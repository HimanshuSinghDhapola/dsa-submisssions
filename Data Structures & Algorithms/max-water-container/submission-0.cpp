// Brute approach
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int ans=INT_MIN, size=heights.size();
        for(int i=0; i<size; i++){
            for(int j=i+1; j<size; j++){
                int trappedWater = min(heights[i], heights[j]) * (j-i);
                ans = max(ans, trappedWater);
            }
        }
        return ans;
    }
};
