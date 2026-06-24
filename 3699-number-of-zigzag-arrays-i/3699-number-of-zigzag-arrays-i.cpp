#include <vector>
#include <numeric>

class Solution {
public:
    int zigZagArrays(int n, int l, int r) {
        int MOD = 1e9 + 7;
        int M = r - l + 1;
        if (M <= 0 || n == 0) return 0;
        if (n == 1) return M;

        // Helper function to count valid arrays for a specific starting condition
        auto countPattern = [&](bool startWithIncrease) -> long long {
            std::vector<long long> dp(M, 1); // Initially, 1 way to place any value at index 0

            for (int i = 1; i < n; ++i) {
                std::vector<long long> next_dp(M, 0);
                // Determine if this step needs to be an increase or decrease
                // Alternate the condition at each step
                bool currentIsIncrease = startWithIncrease ? (i % 2 != 0) : (i % 2 == 0);

                if (currentIsIncrease) {
                    // prev < curr -> next_dp[v] = sum(dp[0] ... dp[v-1])
                    long long prefix_sum = 0;
                    for (int v = 0; v < M; ++v) {
                        next_dp[v] = prefix_sum;
                        prefix_sum = (prefix_sum + dp[v]) % MOD;
                    }
                } else {
                    // prev > curr -> next_dp[v] = sum(dp[v+1] ... dp[M-1])
                    long long suffix_sum = 0;
                    for (int v = M - 1; v >= 0; --v) {
                        next_dp[v] = suffix_sum;
                        suffix_sum = (suffix_sum + dp[v]) % MOD;
                    }
                }
                dp = std::move(next_dp);
            }

            long long total = 0;
            for (long long ways : dp) {
                total = (total + ways) % MOD;
            }
            return total;
        };

        // Pattern 1: a0 < a1 > a2 < a3 ...
        long long up_first = countPattern(true);
        // Pattern 2: a0 > a1 < a2 > a3 ...
        long long down_first = countPattern(false);

        return (up_first + down_first) % MOD;
    }
};
