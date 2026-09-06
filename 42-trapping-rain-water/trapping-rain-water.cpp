class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> start(n);
        vector<int> end(n);
        int smx = -1;
        int emx = -1;
        for(int i=0; i<n; i++) {
            smx = max(smx,height[i]);
            start[i] = smx;
        }
        for(int i=n-1; i>=0; i--) {
            emx = max(emx,height[i]);
            end[i] = emx;
        }
        vector<int> ans(n);
        for(int i=0; i<n; i++) {
            ans[i] = min(start[i],end[i]);
        }
        int result = 0;
        for(int i=0; i<n; i++) {
            result += abs(ans[i] - height[i]);
        }
        return result;
    }
};