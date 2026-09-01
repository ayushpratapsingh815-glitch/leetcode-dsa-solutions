class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& nums,int i,vector<vector<int>>& ans,vector<int>& temp) {
        if(i == nums.size()) {
            sort(temp.begin(),temp.end());
            if(s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }
        //Include
        vector<int> newtemp = temp;
        newtemp.push_back(nums[i]);
        solve(nums,i+1,ans,newtemp);
        //Exclude
        solve(nums,i+1,ans,temp);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        solve(nums,0,ans,temp);
        sort(ans.begin(),ans.end());
        return ans;
    }
};