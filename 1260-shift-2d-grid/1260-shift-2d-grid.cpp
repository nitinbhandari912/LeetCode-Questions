class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int x=k%(m*n);
        for(int i=0;i<x;i++){
            vector<int> col(m);
            for(int r = 0; r < m; r++) {
                col[r] = grid[r][n - 1];
            }
            for(int r = 0; r < m; r++) {
                for(int c = n - 1; c > 0; c--) {
                    grid[r][c] = grid[r][c - 1];
                }
            }
            for(int r = 0; r < m - 1; r++) {
                grid[r + 1][0] = col[r];
            }
            grid[0][0] = col[m - 1];
        }
        return grid;
    }
};