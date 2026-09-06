class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        for(int num : nums) {
            arr.push_back(num);
        }
        for(int num : nums) {
            arr.push_back(num);
        }
        vector<int> ans;
        stack<int> st;
        for(int i=arr.size() - 1; i>=0; i--) {
            while(!st.empty() && st.top() <= arr[i]) {
                st.pop();
            }
            if(st.empty()) {
                ans.push_back(-1);
            } else {
                ans.push_back(st.top());
            }
            st.push(arr[i]);
        }
        vector<int> temp;
        for(int i=2*n-1; i>=n; i--) {
            temp.push_back(ans[i]);
        }
        return temp;
    }
};