class Solution:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        first = cost[0]
        second = cost[1]
        for k in range(2, len(cost)):
            current = cost[k] + min(first, second)
            first = second
            second = current
        return min(first, second)