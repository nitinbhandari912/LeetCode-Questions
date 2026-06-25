class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        cnt_subarray=0
        n=len(nums)
        for i in range(n):
            cnt_target=0
            for j in range(i,n):
                if (nums[j]==target):
                    cnt_target+=1
                if (j-i+1< 2*cnt_target) :
                    cnt_subarray+=1
        return cnt_subarray