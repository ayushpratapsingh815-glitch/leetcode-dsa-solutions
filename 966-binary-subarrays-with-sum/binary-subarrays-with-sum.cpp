class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int currsum = 0;
        mp[0] = 1;
        int count = 0;
        while(right < n) {
            currsum += nums[right];
            if(mp.find(currsum - goal) != mp.end()) {
                count += mp[currsum - goal];
            }
            mp[currsum]++;
            right++;
        }
        return count;
    }
};