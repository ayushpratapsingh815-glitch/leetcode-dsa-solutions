class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        unordered_map<int,int> mp;
        int oddcount = 0;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            oddcount += (nums[i] % 2 != 0);
            if(mp.find(oddcount-k) != mp.end()) {
                count += mp[oddcount-k];
            }
            if(mp.find(oddcount) == mp.end()) {
                mp[oddcount] = 1;
            } else {
                mp[oddcount]++;
            }
        }
        return count;
    }
};