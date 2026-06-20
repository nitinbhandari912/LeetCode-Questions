#include <vector>
#include <algorithm>
#include <iostream>
class Solution {
public:
    int maxBuilding(int n, std::vector<std::vector<int>>& restrictions) {
        restrictions.push_back({1, 0});
        std::sort(restrictions.begin(), restrictions.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        if (restrictions.back()[0] != n) {
            restrictions.push_back({n, n - 1});
        }
        int m = restrictions.size();
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            restrictions[i][1] = std::min(h2, h1 + (id2 - id1));
        }
        for (int i = m - 2; i >= 0; --i) {
            int id1 = restrictions[i][0], h1 = restrictions[i][1];
            int id2 = restrictions[i + 1][0], h2 = restrictions[i + 1][1];
            restrictions[i][1] = std::min(h1, h2 + (id2 - id1));
        }
        int max_height = 0;
        for (int i = 1; i < m; ++i) {
            int id1 = restrictions[i - 1][0], h1 = restrictions[i - 1][1];
            int id2 = restrictions[i][0], h2 = restrictions[i][1];
            int peak = (h1 + h2 + (id2 - id1)) / 2;
            max_height = std::max(max_height, peak);
        }      return max_height;
    }
};