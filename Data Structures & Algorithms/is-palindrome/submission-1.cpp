class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        // filter whole string
        s.erase(remove_if(s.begin(), s.end(), [](unsigned char c){
            return !isalnum(c);
        }), s.end());
        for(int start=0, end=s.length()-1; start<=end; start++, end--){
            if(s[start] != s[end]){
                return false;
            }
        }
        return true;
    }
};
