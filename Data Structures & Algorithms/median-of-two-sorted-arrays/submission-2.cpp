// Optimal approach O(log n) TC and O(1) SC
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int l=0, r=n;

        while(l <= r){
            int px = l+(r-l)/2; // mid elements from nums1 on left side
            int py = (n+m+1)/2 - px; // elements from nums2 on right side

            int a1 = px==0 ? INT_MIN : nums1[px-1];
            int a2 = py==0 ? INT_MIN : nums2[py-1];
            int b1 = px==n ? INT_MAX : nums1[px];
            int b2 = py==m ? INT_MAX : nums2[py];

            if(a1<=b2 && a2<=b1){
                if((n+m)%2==0){
                    return (max(a1, a2) + min(b1, b2))/2.0;
                }else{
                    return max(a1, a2);
                }
            }
            if(a1 > b2){
                r = px-1;
            }else{
                l = px+1;
            }
        }
        return -1;
    }
};
