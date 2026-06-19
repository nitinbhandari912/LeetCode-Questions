class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        vector<int> rep_num(n+1,0);
        for(int i=0;i<nums.size();i++){
            rep_num[nums[i]]++;
        }
        int dublicate=0;
        int missing=0;
        for(int i=1;i<=n;i++){
            if(rep_num[i]==2) dublicate=i;
            if(rep_num[i]==0) missing=i; 
        }
        return {dublicate,missing};
    }
};