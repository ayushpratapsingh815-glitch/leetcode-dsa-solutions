class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_set<int> st;
        int n = nums.size();
        int left = 0;
        int maxlen = 0;
        int maxzeros = 0;
        for(int right = 0; right < n; right++) {
            if(nums[right] == 0) {
                maxzeros++;
            }
            while(maxzeros > k) {
                if(nums[left] == 0) {
                    maxzeros--;
                }
                left++;
            }
            maxlen = max(maxlen,right - left + 1);
        }
        return maxlen;
    }
};