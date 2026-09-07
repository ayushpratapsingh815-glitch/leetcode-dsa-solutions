class Solution {
public:
    int findmaxArea(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && height[st.top()] >= height[i]) {
                st.pop();
            }
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while(!st.empty()) {
            st.pop();
        }
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && height[st.top()] > height[i]) {
                st.pop();
            }
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;
        for(int i=0; i<n; i++) {
            int width = right[i] - left[i] - 1;
            int area = height[i] * width;
            ans = max(ans,area);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m,0);
        for(int j=0; j<m; j++) {
            height[j] = matrix[0][j] == '0' ? 0 : 1;
        }
        int maxArea = findmaxArea(height);
        for(int row=1; row<n; row++) {
            for(int col = 0; col < m; col++) {
                if(matrix[row][col] == '0') {
                    height[col] = 0;
                } else {
                    height[col] += 1;
                }
            }
            maxArea = max(maxArea,findmaxArea(height));
        }
        return maxArea;
    }
};