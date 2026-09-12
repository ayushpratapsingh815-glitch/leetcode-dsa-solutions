class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int right = 0;
        int left = 0;
        int ans = INT_MIN;
        while(right < n) {
            mp[fruits[right]]++;
            while(mp.size() > 2) {
                mp[fruits[left]]--;
                if(mp[fruits[left]] == 0) {
                    mp.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans,right - left + 1);
            right++;
        }
        return ans;
    }
};