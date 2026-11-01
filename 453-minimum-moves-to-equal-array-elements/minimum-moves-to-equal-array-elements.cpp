class Solution {
public:
    int minMoves(vector<int>& nums) {
        int ans = 0;
        int mn = INT_MAX;
        for(int num : nums) {
            mn = min(mn,num);
        }

        for(int num : nums) {
            ans += num - mn;
        }
        return ans;
    }
};