class Solution {
public:
    int max_depth=-1;
    void dfs(int node,int parent,int current_depth,vector<vector<int>>& adj){
        if(max_depth<current_depth){
            max_depth=current_depth;
        }
        for(auto neighbour : adj[node]){
            if(neighbour !=parent){
                dfs(neighbour,node,current_depth+1,adj);
            }
        }
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n=edges.size()+1;
        max_depth=-1;
        vector<vector<int>> adj(n+1);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(1,-1,0,adj);
        if(max_depth<=0) return 0;
        long long ans = 1;
        long long mod = 1000000007;
        int exponent = max_depth - 1;
        for (int i = 0; i < exponent; i++) {
            ans = (ans * 2) % mod;
        }
        
        return ans;
    }
};