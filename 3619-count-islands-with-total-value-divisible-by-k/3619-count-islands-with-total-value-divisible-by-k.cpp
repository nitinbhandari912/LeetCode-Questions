class Solution {
public:
    long long dfs(vector<vector<int>>& grid, int r, int c){
        int n=grid.size();
        int m=grid[0].size();
        if(r<0 || r>=n || c<0 || c>=m || grid[r][c]==0){
            return 0;
        }
        long long sum = grid[r][c];
        grid[r][c] = 0;
        sum += dfs(grid, r, c - 1);
        sum += dfs(grid, r, c + 1);
        sum += dfs(grid, r - 1, c);
        sum += dfs(grid, r + 1, c);
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        if (grid.empty() || grid[0].empty() || k <= 0) return 0;
        int n=grid.size();
        int m=grid[0].size();
        int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] != 0) {
                    long long islandSum = dfs(grid, i, j);
                    if (islandSum > 0 && islandSum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};