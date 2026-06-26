class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long cnt_subarray=0;
        int n=nums.size();
        vector<int> fr(2*n+1,0);
        int curr_sum=0;
        fr[0+n]=1;
        long long small_cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                small_cnt+=fr[curr_sum+n];
                curr_sum+=1;
            }
            else{
                curr_sum-=1;
                small_cnt-=fr[curr_sum+n];
            }
            cnt_subarray+=small_cnt;
            fr[curr_sum+n]++;
        }
        return cnt_subarray;
    }
};