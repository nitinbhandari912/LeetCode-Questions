class Solution {
public:
    bool winnerSquareGame(int n) {
        int root=sqrt(n);
        if(root*root==n) return true;
        vector<bool> dp(n + 1, false);
        for(int i=0;i<=n;i++){
            for(int k=1;k*k<=i;k++){
                if(dp[i-k*k]==false){
                    dp[i]=true;
                    break;
                }
            }
        }
        return dp[n];
    }
};