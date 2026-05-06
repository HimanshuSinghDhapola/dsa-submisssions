// Brute force approach TC: O(n), SC: O(m+n)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int size = n+m;
        vector<int> arr(size);
        int i=0, j=0, k=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                arr[k++] = nums1[i++];
            }else{
                arr[k++] = nums2[j++];
            }
        }
        while(i<n){
            arr[k++] = nums1[i++];
        }
        while(j<m){
            arr[k++] = nums2[j++];
        }

        return size%2 == 0 ? ((arr[size/2] + arr[(size/2)-1]) / 2.00) : arr[size/2]; 
    }
};
