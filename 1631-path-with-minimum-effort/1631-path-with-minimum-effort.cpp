class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights[0].size();
        int n=heights.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq; 
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[0][0]=0;
        pq.push({0,{0,0}});
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int diff=it.first;
            int row=it.second.first;
            int col=it.second.second;
            for(int i=0;i<4;i++){
                int newr=row+dr[i];
                int newc=col+dc[i];
                if(row==n-1 && col==m-1) return diff;
                if(newr>=0 && newc>=0 && newr<n && newc<m){
                    int neweffort=max(abs(heights[row][col]-heights[newr][newc]),diff);
                    if(neweffort<dis[newr][newc]){
                        dis[newr][newc]=neweffort;
                        pq.push({neweffort,{newr,newc}});
                    }
                }
            }
        }
        return 0;
    }
};