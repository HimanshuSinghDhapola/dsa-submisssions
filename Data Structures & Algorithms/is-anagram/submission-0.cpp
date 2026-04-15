class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        vector<int> count(26, 0);
        for(auto &it: s){
            count[it-'a']++;
        }
        for(auto &it: t){
            count[it-'a']--;
        }
        return all_of(begin(count), end(count), [](int element){return element == 0;});
    }
};
