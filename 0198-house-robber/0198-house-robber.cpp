class Solution {
public:
    int dfs(vector<int>& nums,int index,vector<int>& memo){
        if(index>=nums.size()){
            return 0;
        }
        if(memo[index]!=-1) return memo[index];
        int rob=nums[index]+dfs(nums,index+2,memo);
        int skip=dfs(nums,index+1,memo);
        return memo[index]= max(rob,skip);
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(),-1);
        return dfs(nums,0,memo);
    }
};