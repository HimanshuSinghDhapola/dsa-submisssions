class Solution {
public:

    string encode(vector<string>& strs) {
        string code;
        for(auto &it: strs){
            code += to_string(it.size()) + '#' + it;
        }
        return code;
    }

    vector<string> decode(string s) {
        vector<string> ans;
        int i=0;
        while(i<s.size()){
            int j=i;
            while(s[j] != '#') j++;

            int len = stoi(s.substr(i, j-i));

            j++;
            string word = s.substr(j, len);
            ans.push_back(word);

            i = j+len;
        }
        return ans;
    }
};
