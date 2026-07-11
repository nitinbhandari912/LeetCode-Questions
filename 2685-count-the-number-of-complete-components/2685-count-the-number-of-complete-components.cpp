class Solution {
public:
    void dfs(vector<vector<int>>& adj,int node,vector<int>& vis,int& v_count, int& e_count){
        if(vis[node]==1) return ;
        vis[node]=1;
        v_count++;
        e_count += adj[node].size();
        for(auto it :adj[node]){
            if(vis[it]==1) continue;
            else dfs(adj, it, vis, v_count, e_count);
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int cnt=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i]==1) continue;
            else{
                int v_count=0;
                int e_count=0;
                dfs(adj,i,vis,v_count,e_count);
                if(e_count == v_count * (v_count - 1))cnt++;
            }
        }
        return cnt;
    }
};