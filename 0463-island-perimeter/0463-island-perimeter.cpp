class Solution {
public:
    int drow[4]={-1,0,0,1};
    int dcol[4]={0,1,-1,0};
    void dfs(vector<vector<int>>& grid,int& parameter,int row,int col,vector<vector<int>>& vis){
        if(vis[row][col]==1) return ;
        vis[row][col]=1;
        for(int i=0;i<4;i++){
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if (nrow < 0 || nrow >= grid.size() || ncol < 0 || ncol >= grid[0].size()) {
                parameter++;
            }
            else if (grid[nrow][ncol] == 0) {
                parameter++;
            }
            else if (vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1) {
                dfs(grid, parameter, nrow, ncol, vis);
            }
        }
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int parameter=0;
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, parameter, i, j, vis);
                    return parameter; 
                }
            }
        }
        return parameter;
    }
};