class Solution {
public:
    int dfsA(vector<int>& nums,int index,vector<int>& memo){
        if(index>=nums.size()-1) return 0;
        int n=nums.size();
        if(memo[index]!=-1){
            return memo[index];
        }
        int curr=nums[index]+ dfsA(nums,(index+2),memo);
        int skip=dfsA(nums,(index+1),memo);
        return memo[index]=max(curr,skip);
    }
    int dfsB(vector<int>& nums,int index,vector<int>& memo1){
        if(index>=nums.size()) return 0;
        int n=nums.size();
        if(memo1[index]!=-1){
            return memo1[index];
        }
        int curr=nums[index]+ dfsB(nums,(index+2),memo1);
        int skip=dfsB(nums,(index+1),memo1);
        return memo1[index]=max(curr,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        
        vector<int> memo(nums.size(),-1);
        vector<int> memo1(nums.size(),-1);
        return max(dfsA(nums,0,memo),dfsB(nums,1,memo1));
    }
};