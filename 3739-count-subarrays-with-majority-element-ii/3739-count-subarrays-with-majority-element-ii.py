class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n=len(nums)
        cnt_subarray=0
        fr=[0]*(2*n+1)
        curr_sum=0
        fr[0+n]=1
        small_cnt=0
        for i in range(n):
            if nums[i]==target :
                small_cnt+=fr[curr_sum+n]
                curr_sum+=1
            else :
                curr_sum-=1
                small_cnt-=fr[curr_sum+n]
            cnt_subarray+=small_cnt
            fr[curr_sum+n]+=1
        return cnt_subarray