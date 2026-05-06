// Brute force approach TC: O(n), SC: O(1)

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(), m=nums2.size();
        int size = n+m;
        int idx1 = (size/2) - 1, idx2 = size/2;
        int ele1 = -1, ele2 = -1;
        int i=0, j=0, k=0;
        while(i<n && j<m){
            if(nums1[i] < nums2[j]){
                if(k == idx1){
                    ele1 = nums1[i];
                }
                if(k == idx2){
                    ele2 = nums1[i];
                }
                i++;
            }else{
                if(k == idx1){
                    ele1 = nums2[j];
                }
                if(k == idx2){
                    ele2 = nums2[j];
                }
                j++;
            }
            k++;
        }
        while(i<n){
            if(k == idx1){
                ele1 = nums1[i];
            }
            if(k == idx2){
                ele2 = nums1[i];
            }
            i++;
            k++;
        }
        while(j<m){
            if(k == idx1){
                ele1 = nums2[j];
            }
            if(k == idx2){
                ele2 = nums2[j];
            }
            j++;
            k++;
        }

        return size%2 == 0 ? (ele1 + ele2)/2.00 : ele2; 
    }
};
