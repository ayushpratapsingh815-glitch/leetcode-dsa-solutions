class Solution {
public:
    void solve(string s,vector<vector<string>>& ans,vector<string>& temp) {
        if(s.size() == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<s.size(); i++) {
            string part = s.substr(0,i+1);
            if(ispalindrome(part)) {
                temp.push_back(part);
                solve(s.substr(i+1),ans,temp);
                temp.pop_back();
            }
        }
    }
    bool ispalindrome(string str) {
        int st = 0;
        int ed = str.size() - 1;
        while(st <= ed) {
            if(str[st] != str[ed]) {
                return false;
            }
            st++;
            ed--;
        }
        return true;
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        solve(s,ans,temp);
        return ans;
    }
};