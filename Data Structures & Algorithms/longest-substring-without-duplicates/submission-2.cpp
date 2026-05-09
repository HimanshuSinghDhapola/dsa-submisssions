// last seen index approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0, size = s.length();
        int maxi = 0;
        vector<int> seen(256, -1);
        for(int r=0; r<size; r++){
            if(seen[s[r]] >= l){
                l = seen[s[r]] + 1;
            }
        
            seen[s[r]] = r;
            int len = r-l+1;
            maxi = max(maxi, len);
        }
        return maxi;
    }
};
