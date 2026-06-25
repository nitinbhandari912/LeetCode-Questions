class Solution:
    def dominantIndex(self, nums: List[int]) -> int:
        res=nums.copy()
        nums.sort()
        n=len(nums)
        if(nums[n-2]*2<=nums[n-1]):
            for i in range(n):
                if nums[n-1]==res[i] :
                    return i
        return -1