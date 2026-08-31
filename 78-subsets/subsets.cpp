class Solution {
public:
    void solve(vector<int> curr,int i,vector<int>& nums,vector<vector<int>>& ans) {
        if(i == nums.size()) {
            ans.push_back(curr);
            return;
        }
        vector<int> newcurr = curr;
        newcurr.push_back(nums[i]);
        //Yes char want to add
        solve(newcurr,i+1,nums,ans);

        //No char do not want
        solve(curr,i+1,nums,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        solve(curr,0,nums,ans);
        return ans;
    }
};