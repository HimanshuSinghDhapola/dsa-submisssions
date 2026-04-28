// Space complexity O(1); Time complexity O(N)
// Two pointers approach
class Solution {
public:
    int trap(vector<int>& height) {
        int lMax, rMax, total, left, right;
        lMax = rMax = total = 0; left = 0; right = height.size()-1;

        while(left < right){
            if(height[left] < height[right]){
                if(lMax > height[left]){
                    total += lMax - height[left];
                }else{
                    lMax = height[left];
                }
                left++;
            }else{
                if(rMax > height[right]){
                    total += rMax - height[right];
                }else{
                    rMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};
