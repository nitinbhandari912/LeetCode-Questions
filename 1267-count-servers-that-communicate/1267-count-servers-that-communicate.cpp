class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int> rowCnt(n,0);
        vector<int> colCnt(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int communicatingServer=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if (grid[i][j] == 1 && (rowCnt[i]>1 || colCnt[j]>1)) {
                    communicatingServer++;
                }
            }
        }
        return communicatingServer;   
    }
};