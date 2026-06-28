class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int low =0;
        int high=1;
        int n=nums.size();
        int max_ht=0;
        while(low<n && high<n){
            if(nums[high-1]<nums[high]){
                high++;
            }
            else{
                max_ht=max(max_ht,high-low);
                low=high;
                high=low+1;
            }
        }
        max_ht=max(max_ht,high-low);
        return max_ht;
    }
};