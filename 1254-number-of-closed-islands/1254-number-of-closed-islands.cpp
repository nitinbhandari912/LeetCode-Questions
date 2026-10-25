class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r,int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==1){
            return ;
        }
        grid[r][c]=1;
        dfs(grid,r,c-1);
        dfs(grid,r,c+1);
        dfs(grid,r-1,c);
        dfs(grid,r+1,c);
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            if(grid[i][0]==0) dfs(grid,i,0);
            if(grid[i][m-1]==0) dfs(grid,i,m-1);
        }
        for(int i=0;i<m;i++){
            if(grid[0][i]==0) dfs(grid,0,i);
            if(grid[n-1][i]==0) dfs(grid,n-1,i);
        }
        int closedIsland =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    dfs(grid,i,j);
                    closedIsland++;
                }
            }
        }
        return closedIsland;
    }
};