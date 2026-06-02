class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<n){
            int sum=INT_MIN;
            int index=0;
            if(i+nums[i]>=nums.size()-1){
                return true;
            }
            for(int j=i+1;j<=i+nums[i];j++){
                if(sum<nums[j]+j){
                    sum=nums[j]+j;
                    index=j;
                }
            }
            if(nums[index]==0){
                return false;
            }
            i=index;
        }
        return true;
    }
};