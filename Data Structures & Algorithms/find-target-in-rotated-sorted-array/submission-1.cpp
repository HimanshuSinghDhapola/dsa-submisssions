class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0, r=nums.size() - 1;
        // find the inflection point i.e. pivot index
        while(l<r){
            int mid = l + (r-l)/2;
            if(nums[mid] > nums[r]){
                l = mid+1;
            }else{
                r = mid;
            }
        }
        int pivotIndex = l;
        l=0, r=nums.size()-1;
        // Deciding the boundaries
        if(target >= nums[pivotIndex] && target <= nums[r]){
            l = pivotIndex;
        }else{
            r = pivotIndex-1;
        }

        // find the element in the new boundaries
        while(l<=r){
            int mid = l + (r-l)/2;
            if(target > nums[mid]){
                l = mid+1;
            }else if(target < nums[mid]){
                r = mid-1;
            }else{
                return mid;
            }
        }
        return -1;
    }
};
