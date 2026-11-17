#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.length();
        vector<vector<int>> divisors(n + 1);
        for (int m = 1; m <= n; ++m) {
            for (int d = 1; d < m; ++d) {
                if (m % d == 0) {
                    divisors[m].push_back(d);
                }
            }
        }
        vector<vector<int>> cost(n, vector<int>(n, 1e9));
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                for (int d : divisors[len]) {
                    int current_cost = 0;
                    for (int offset = 0; offset < d; ++offset) {
                        int l = i + offset;
                        int r = i + len - d + offset;
                        while (l < r) {
                            if (s[l] != s[r]) {
                                current_cost++;
                            }
                            l += d;
                            r -= d;
                        }
                    }
                    cost[i][j] = min(cost[i][j], current_cost);
                }
            }
        }
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 1e9));
        dp[0][0] = 0;
        for (int p = 1; p <= k; ++p) {
            for (int i = p; i <= n; ++i) {
                for (int j = p - 1; j < i; ++j) {
                    dp[i][p] = min(dp[i][p], dp[j][p - 1] + cost[j][i - 1]);
                }
            }
        }
        return dp[n][k];
    }
};