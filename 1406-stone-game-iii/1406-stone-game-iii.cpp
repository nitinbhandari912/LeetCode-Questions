class Solution {
public:
    int maxdiff(vector<int>& stoneValue,int i,vector<int>& dp){
        if(i>=stoneValue.size()){
            return 0;
        }
        if(dp[i]!=-1e9){
            return dp[i];
        }
        int max_diff=-1e9;
        int stone=0;
        for(int k=0;k<3 && i+k<stoneValue.size();k++){
            stone+=stoneValue[i+k];
            int curr_diff=stone-maxdiff(stoneValue,i+k+1,dp);
            max_diff=max(max_diff,curr_diff);
        }
        return dp[i]=max_diff;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n=stoneValue.size();
        vector<int> dp(n,-1e9);
        int diff=maxdiff(stoneValue,0,dp);
        if(diff<0) return "Bob";
        if(diff>0) return "Alice";
        else return "Tie";
    }
};