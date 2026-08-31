class Solution {
public:
    void solve(string curr,int n,vector<string>& ans) {
        if(curr.size() == 2*n) {
            if(isvalid(curr)) {
                ans.push_back(curr);
            }
            return;
        }

        solve(curr+"(",n,ans);
        solve(curr+")",n,ans);
    }
    bool isvalid(string curr) {
        stack<char> st;
        vector<char> arr(curr.begin(),curr.end());
        for(char ch : arr) {
            if(ch == '(') {
                st.push(ch);
            } else {
                if(st.empty()) {
                    return false;
                }
                if(ch == ')' && st.top() == '(') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        if(st.empty()) {
            return true;
        } else {
            return false;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve("(",n,ans);
        return ans;
    }
};