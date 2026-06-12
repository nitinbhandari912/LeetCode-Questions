#include <vector>
#include <numeric>

using namespace std;

class Solution {
    vector<int> parent;
    vector<int> rank;
    vector<int> ancestor;
    vector<bool> visited;
    vector<int> depth;
    vector<int> lca_results;
    long long mod = 1000000007;
    int find_set(int v) {
        if (v == parent[v]) return v;
        return parent[v] = find_set(parent[v]);
    }
    void union_sets(int a, int b, int new_ancestor) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rank[a] < rank[b]) swap(a, b);
            parent[b] = a;
            if (rank[a] == rank[b]) rank[a]++;
        }
        ancestor[find_set(a)] = new_ancestor;
    }
    void tarjanDFS(int node, int p, int d, vector<vector<int>>& adj, vector<vector<pair<int, int>>>& query_adj) {
        visited[node] = true;
        depth[node] = d;
        ancestor[node] = node;
        for (int neighbor : adj[node]) {
            if (neighbor != p) {
                tarjanDFS(neighbor, node, d + 1, adj, query_adj);
                union_sets(node, neighbor, node);
            }
        }
        for (auto& query : query_adj[node]) {
            int other_node = query.first;
            int query_index = query.second;
            if (visited[other_node]) {
                lca_results[query_index] = ancestor[find_set(other_node)];
            }
        }
    }
    long long power(long long base, long long exp) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp % 2 == 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp /= 2;
        }
        return res;
    }
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
       vector<vector<pair<int, int>>> query_adj(n + 1);
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (u == v) continue;
            query_adj[u].push_back({v, i});
            query_adj[v].push_back({u, i});
        }
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0);
        rank.assign(n + 1, 0);
        ancestor.resize(n + 1);
        visited.assign(n + 1, false);
        depth.assign(n + 1, 0);
        lca_results.assign(queries.size(), -1);
        tarjanDFS(1, 0, 0, adj, query_adj);
        vector<int> ans;
        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (u == v) {
                ans.push_back(0);
                continue;
            }
            int lca = lca_results[i];
            int path_distance = depth[u] + depth[v] - 2 * depth[lca];
            if (path_distance <= 0) {
                ans.push_back(0);
            } else {
                ans.push_back(power(2, path_distance - 1));
            }
        }
        return ans;
    }
};