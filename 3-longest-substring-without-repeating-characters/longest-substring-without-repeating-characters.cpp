class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) {
            return 0;
        }
        unordered_map<char,int> mp;
        int n = s.size();
        int left = 0;
        int right = 0;
        int mx = INT_MIN;
        while(right < n) {
            mp[s[right]]++;
            while(mp[s[right]] > 1) {
                mp[s[left]]--;
                if(mp[s[left]] == 0) {
                    mp.erase(s[left]);
                }
                left++;
            }
            right++;
            mx = max(mx,right-left);
        }
        return mx;
    }
};