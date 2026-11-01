class Solution {
public:
    void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis,int &ans) {
        if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 1) {
            return;
        }
        vis[i][j] = true;
        ans++;

        dfs(i+1,j,n,m,grid,vis,ans);
        dfs(i,j+1,n,m,grid,vis,ans);
        dfs(i-1,j,n,m,grid,vis,ans);
        dfs(i,j-1,n,m,grid,vis,ans);
        
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    count++;
                }
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j] && (i == 0 || j == 0 || i == n-1 || j == m-1)) {
                    dfs(i,j,n,m,grid,vis,ans);
                }
            }
        }
        return count - ans;
    }
};