class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<pair<long long,int>> adj[n];
        int mod=(int)(1e9+7);
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<long long> dis(n,1e18);
        vector<long long> ways(n,0);
        dis[0]=0;
        ways[0]=1;
        pq.push({0,0});
        while(!pq.empty()){
            long long dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if (dist > dis[node]) continue;
            for(auto it: adj[node]){
                int adjNode=it.first;
                long long edw=it.second;
                if(dist+edw<dis[adjNode]){
                    dis[adjNode]=dist+edw;
                    pq.push({dist+edw,adjNode});
                    ways[adjNode]=ways[node];
                }
                else if(edw+dist==dis[adjNode]){
                    ways[adjNode]=(ways[adjNode]+ways[node])%mod;   
                }
            }
        }
        return ways[n-1]%mod;
    }
};