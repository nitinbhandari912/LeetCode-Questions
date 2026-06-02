class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        vector<int> preMax(nums.size(),-1);
        preMax[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            preMax[i]=max(preMax[i-1],nums[i]);
        }
        int smin=INT_MAX;
        vector<int> ans(nums.size(),0);
        for(int i=nums.size()-1;i>=0;i--){
            if(preMax[i]>smin){
                ans[i]=ans[i+1];
            }
            else{
                ans[i]=preMax[i];
            }
            smin=min(smin,nums[i]);
        }
        return ans;
    }
};