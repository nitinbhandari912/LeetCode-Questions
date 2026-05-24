class Solution {
public:
    int dfs(vector<int>& arr, int d, int i, int n,vector<int>& dp) {
        if(dp[i]!=-1) return dp[i];
        int max_from_here = 1;
        for (int j = i + 1; j <= i + d && j < n; j++) {
            if (arr[j] >= arr[i]) break; 
            max_from_here = max(max_from_here, 1 + dfs(arr, d, j, n,dp));
        }
        for (int j = i - 1; j >= i - d && j >= 0; j--) {
            if (arr[j] >= arr[i]) break;
            max_from_here = max(max_from_here, 1 + dfs(arr, d, j, n,dp));
        }
        return dp[i]=max_from_here;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        int global_max = 0;
        vector<int> dp(n,-1);
        for (int i = 0; i < n; i++) {
            global_max = max(global_max, dfs(arr, d, i, n,dp));
        }
        return global_max;
    }
};