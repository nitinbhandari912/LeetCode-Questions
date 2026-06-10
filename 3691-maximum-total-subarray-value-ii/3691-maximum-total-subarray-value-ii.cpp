#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

class SparseTable {
    vector<vector<int>> st_max;
    vector<vector<int>> st_min;
    vector<int> lg;
public:
    SparseTable(const vector<int>& nums) {
        int n = nums.size();
        int max_log = log2(n) + 1;
        st_max.assign(n, vector<int>(max_log));
        st_min.assign(n, vector<int>(max_log));
        lg.assign(n + 1, 0);

        for (int i = 2; i <= n; i++) lg[i] = lg[i / 2] + 1;

        for (int i = 0; i < n; i++) {
            st_max[i][0] = nums[i];
            st_min[i][0] = nums[i];
        }

        for (int j = 1; j < max_log; j++) {
            for (int i = 0; i + (1 << j) <= n; i++) {
                st_max[i][j] = max(st_max[i][j - 1], st_max[i + (1 << (j - 1))][j - 1]);
                st_min[i][j] = min(st_min[i][j - 1], st_min[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    int queryValue(int l, int r) {
        int k = lg[r - l + 1];
        int mx = max(st_max[l][k], st_max[r - (1 << k) + 1][k]);
        int mn = min(st_min[l][k], st_min[r - (1 << k) + 1][k]);
        return mx - mn;
    }
};

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        SparseTable st(nums);
        
        // Max-heap stores elements as: {subarray_value, {left_idx, right_idx}}
        priority_queue<pair<int, pair<int, int>>> pq;
        
        // Initialize heap with the maximum possible right bound for every left bound
        for (int l = 0; l < n; l++) {
            int val = st.queryValue(l, n - 1);
            pq.push({val, {l, n - 1}});
        }
        
        long long max_total_sum = 0;
        
        // Extract the k largest distinct subarrays
        for (int step = 0; step < k; step++) {
            if (pq.empty()) break;
            
            auto top = pq.top();
            pq.pop();
            
            int val = top.first;
            int l = top.second.first;
            int r = top.second.second;
            
            max_total_sum += val;
            
            // If we can shrink the right boundary further, push the next best option
            if (r > l) {
                int next_val = st.queryValue(l, r - 1);
                pq.push({next_val, {l, r - 1}});
            }
        }
        
        return max_total_sum;
    }
};