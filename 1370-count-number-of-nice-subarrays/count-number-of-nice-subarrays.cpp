class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n = nums.size();
        int right = 0;
        int count = 0;
        int oddcount = 0;
        mp[0] = 1;
        while(right < n) {
            oddcount += (nums[right] % 2);
            if(mp.find(oddcount - k) != mp.end()) {
                count += mp[oddcount - k];
            }
            mp[oddcount]++;
            right++;
        }
        return count;
    }
};