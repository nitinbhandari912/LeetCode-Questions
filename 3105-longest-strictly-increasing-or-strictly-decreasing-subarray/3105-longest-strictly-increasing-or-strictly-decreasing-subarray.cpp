class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max_len = 1;
        int inc_len = 1;
        int dec_len = 1;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]>nums[i-1]){
                inc_len++;
                dec_len=1;
            }
            else if(nums[i]<nums[i-1]){
                inc_len=1;
                dec_len++;
            }
            else{
                inc_len=1;
                dec_len=1;
            }
            max_len=max({inc_len,dec_len,max_len});
        }
        return max_len;
    }
};