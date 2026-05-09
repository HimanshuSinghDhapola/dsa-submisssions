// frequency count approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, size = s.length();
        int maxi = 0;
        vector<int> arr(256, 0);
        for(int r=0; r<size; r++){
            if(arr[s[r]] != 0){
                while(arr[s[r]] != 0){
                    arr[s[l]]--;
                    l++;
                }
            }
            arr[s[r]]++;
            int len = r-l+1;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};
