class Solution:
    def findLengthOfLCIS(self, nums: List[int]) -> int:
        low=0
        high=1
        max_ht=0
        n=len(nums)
        while low<n and high<n :
            if nums[high-1]<nums[high]:
                high+=1
            else :
                max_ht=max(max_ht,high-low)
                low=high
                high=low+1
        max_ht=max(max_ht,high-low)
        return max_ht