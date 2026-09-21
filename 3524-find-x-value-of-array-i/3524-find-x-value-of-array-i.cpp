class Solution {
public:
    vector<long long> resultArray(std::vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);
        for (int num : nums) {
            vector<long long> next_dp(k, 0);
            int val = num % k;
            next_dp[val] += 1;
            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int next_r = (r * val) % k;
                    next_dp[next_r] += dp[r];
                }
            }
            dp = next_dp;
            for (int r = 0; r < k; ++r) {
                ans[r] += dp[r];
            }
        }
        return ans;
    }
};