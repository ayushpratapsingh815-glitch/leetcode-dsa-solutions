class Solution {
public:
    void solve(string digits,int idx,unordered_map<char,string>& mp,vector<string>& temp,string& s) {
        if(s.size() == digits.size()) {
            temp.push_back(s);
            return;
        }
        char ch = digits[idx];
        string str = mp[ch];
        for(int i=0; i<str.size(); i++) {
            s += str[i];
            solve(digits,idx+1,mp,temp,s);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> temp;
        string s;
        unordered_map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        solve(digits,0,mp,temp,s);
        return temp;
    }
};