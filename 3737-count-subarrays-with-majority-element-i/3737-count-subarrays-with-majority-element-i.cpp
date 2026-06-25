class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt_subarray=0;
        int n=nums.size();
        for(int i=0; i<n;i++){
            int target_cnt=0;
            for(int j=i;j<n;j++){
                if(nums[j]==target) target_cnt++;
                if(j-i+1<2*target_cnt) cnt_subarray++;
            }
        }
        return cnt_subarray;
    }
};