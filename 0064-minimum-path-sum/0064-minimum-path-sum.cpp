class Solution {
public:
    int helper(vector<vector<int>>& grid, int r, int c , vector<vector<int>>& memo){
        if (r < 0 || c < 0) return INT_MAX;
        if (r == 0 && c == 0) return grid[0][0];
        if (memo[r][c] != -1) return memo[r][c];
        int fromTop = helper(grid, r - 1, c, memo);
        int fromLeft = helper(grid, r, c - 1, memo);
        return memo[r][c] = grid[r][c] + min(fromTop, fromLeft);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return helper(grid, m - 1, n - 1, memo);
    }
};