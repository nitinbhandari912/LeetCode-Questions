class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n + 1);
        for (const auto& road : roads) {
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        int min_score = INT_MAX;
        queue<int> q;
        vector<bool> visited(n + 1, false);
        q.push(1);
        visited[1] = true;
        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            for(auto edge : adj[frontNode]){
                int next_node = edge.first;
                int distance = edge.second;
                min_score = min(min_score, distance);
                if (!visited[next_node]) {
                    visited[next_node] = true;
                    q.push(next_node);
                }
            }
        }
        return min_score;
    }
};