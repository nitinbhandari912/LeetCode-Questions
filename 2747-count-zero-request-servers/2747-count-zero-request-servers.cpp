class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        int q_size = queries.size();
        vector<int> arr(q_size);
        vector<pair<int, int>> sorted_queries(q_size);
        for (int i = 0; i < q_size; i++) {
            sorted_queries[i] = {queries[i], i};
        }
        sort(sorted_queries.begin(), sorted_queries.end());
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<int> server_freq(n + 1, 0);
        int unique_active = 0;
        int left = 0, right = 0;
        int m = logs.size();
        for (int i = 0; i < q_size; i++) {
            int high = sorted_queries[i].first;
            int low = high - x;
            int original_idx = sorted_queries[i].second;
            while (right < m && logs[right][1] <= high) {
                int server = logs[right][0];
                if (server_freq[server] == 0) {
                    unique_active++;
                }
                server_freq[server]++;
                right++;
            }
            while (left < m && logs[left][1] < low) {
                int server = logs[left][0];
                server_freq[server]--;
                if (server_freq[server] == 0) {
                    unique_active--;
                }
                left++;
            }
            arr[original_idx] = n - unique_active;
        }
        return arr;
    }
};