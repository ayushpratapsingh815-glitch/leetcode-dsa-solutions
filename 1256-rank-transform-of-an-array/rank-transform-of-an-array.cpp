class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> nums;
        for(int num : arr) {
            nums.push_back(num);
        }
        sort(arr.begin(),arr.end());
        int count = 0;
        for(int i=0; i<arr.size(); i++) {
            if(mp.find(arr[i]) == mp.end()) {
                count++;
                mp[arr[i]] = count;
            }
        }
        for(int i=0; i<nums.size(); i++) {
            nums[i] = mp[nums[i]];
        }
        return nums;
    }
};