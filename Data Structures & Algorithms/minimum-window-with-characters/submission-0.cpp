class Solution {
public:
    string minWindow(string s, string t) {
        int s_size=s.length(), t_size=t.length();
        if(t_size > s_size){
            return "";
        }
        unordered_map<char, int> mpp;
        for(auto it: t){
            mpp[it]++;
        }
        int i=0, j=0, countRequired=t_size;
        int windowSize=INT_MAX, startIdx=0;
        while(j<s_size){
            // expand window
            if(mpp[s[j]] > 0){
                countRequired--;
            }
            mpp[s[j]]--;

            while(countRequired == 0){
                if(j-i+1 < windowSize){
                    windowSize = j-i+1;
                    startIdx=i;
                }
                mpp[s[i]]++;
                if(mpp[s[i]]>0){
                    countRequired++;
                }
                i++;
            }

            j++;
        }
        return (windowSize == INT_MAX)
                ? ""
                : s.substr(startIdx, windowSize);
    }
};
