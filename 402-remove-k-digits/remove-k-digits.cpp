class Solution {
public:
    string removeKdigits(string num, int k) {
        if(num.size() == 1 && k == 1) {
            return "0";
        }
        int m = k;
        vector<int> nums;
        for(int i=0; i<num.size(); i++) {
            nums.push_back(num[i] - '0');
        }
        stack<int> st;
        for(int i=0; i<nums.size(); i++) {
            while(!st.empty() && k > 0 && st.top() > nums[i]) {
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        string str;
        while(k > 0) {
            st.pop();
            k--;
        }
        while(!st.empty()) {
            str += st.top() + '0';
            st.pop();
        }
        reverse(str.begin(),str.end());
        while(str.size() > 1 && str[0] == '0') {
            str.erase(0,1);
        }
        return str.empty() ? "0" : str;
    }
};