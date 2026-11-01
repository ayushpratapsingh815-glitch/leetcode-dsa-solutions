class Solution {
public:
    // void dfs(int i,int j,int n,int m,vector<vector<int>>& grid,vector<vector<bool>>& vis) {
    //     if(i < 0 || j < 0 || i >= n || j >= m || vis[i][j] || grid[i][j] != 2) {
    //         return;
    //     }

    //     vis[i][j] = true;

    //     dfs(i+1,j,n,m,grid,vis);
    //     dfs(i,j+1,n,m,grid,vis);
    //     dfs(i-1,j,n,m,grid,vis);
    //     dfs(i,j-1,n,m,grid,vis);
    // }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        queue<pair<pair<int,int>,int>> q;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i,j},0});
                }
            }
        }
        while(!q.empty()) {
            int i = q.front().first.first;
            int j = q.front().first.second;
            int time = q.front().second;
            q.pop();
            ans = max(ans,time);

            if(i - 1 >= 0 && !vis[i-1][j] && grid[i-1][j] == 1) {
                q.push({{i-1,j},time+1});
                vis[i-1][j] = true;
            }
            if(i + 1 < n && !vis[i+1][j] && grid[i+1][j] == 1) {
                q.push({{i+1,j},time+1});
                vis[i+1][j] = true;
            }
            if(j - 1 >= 0 && !vis[i][j-1] && grid[i][j-1] == 1) {
                q.push({{i,j-1},time+1});
                vis[i][j-1] = true;
            }
            if(j + 1 < m && !vis[i][j+1] && grid[i][j+1] == 1) {
                q.push({{i,j+1},time+1});
                vis[i][j+1] = true;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) {
                    return -1;
                }
            }
        }
        return ans;

    }
};