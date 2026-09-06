class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        int mx = -1;
        for(int i=arr.size()-1; i>=0; i--) {
            ans.push_back(mx);
            mx = max(mx,arr[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};