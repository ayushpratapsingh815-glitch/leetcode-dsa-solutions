class Solution {
public:
    void solve(vector<int>& nums,int i,int k,int n,vector<vector<int>>& ans,vector<int>& temp) {
        if(temp.size() == k && n == 0) {
            ans.push_back(temp);
            return;
        }
        if(i == nums.size()) {
            return;
        }
        //Include
        temp.push_back(nums[i]);
        solve(nums,i+1,k,n - nums[i],ans,temp);

        //Exclude
        temp.pop_back();
        solve(nums,i+1,k,n,ans,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=1; i<=9; i++) {
            nums.push_back(i);
        }
        solve(nums,0,k,n,ans,temp);
        return ans;
    }
};