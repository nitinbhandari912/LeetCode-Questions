class Solution:
    def findGCD(self, nums: List[int]) -> int:
        mini=1e9
        maxi=-1e9
        for num in nums :
            mini=min(mini,num)
            maxi=max(maxi,num)
        return math.gcd(mini,maxi)