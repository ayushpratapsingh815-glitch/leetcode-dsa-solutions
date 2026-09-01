class Solution {
public:
    set<vector<int>> s;
    void solve(vector<int>& candidates, int target,int i,vector<vector<int>>& ans,vector<int>& temp,int n) {
        if(i == n || target < 0) {
            return;
        }
        if(target == 0) {
            if(s.find(temp) == s.end()) {
                ans.push_back(temp);
                s.insert(temp);
            }
            return;
        }
        //Include only one time
        temp.push_back(candidates[i]);
        solve(candidates,target - candidates[i],i+1,ans,temp,n);

        //Include multiple times
        solve(candidates,target - candidates[i],i,ans,temp,n);

        temp.pop_back();

        //Exclude

        solve(candidates,target,i+1,ans,temp,n);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n = candidates.size();
        solve(candidates,target,0,ans,temp,n);
        return ans;
    }
};