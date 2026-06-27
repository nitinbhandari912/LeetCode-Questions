import collections
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        # Step 1: Count the frequency of every number
        count = collections.Counter(nums)
        
        # Step 2: Handle the edge case for 1s.
        # Since 1 * 1 = 1, a chain of ones looks like [1, 1, 1...].
        # It must be an odd length, so if count[1] is even, we take count[1] - 1.
        ans = count[1] - (count[1] % 2 == 0) if 1 in count else 1
        
        max_num = max(nums)
        
        # Step 3: Check every other number as a potential base 'x'
        for num in nums:
            if num == 1:
                continue
                
            current_length = 0
            x = num
            
            # Keep squaring x as long as we have at least 2 copies of it
            while x <= max_num and x in count and count[x] >= 2:
                current_length += 2
                x *= x  # Move to the next power: x^2, x^4, x^8...
            
            # 'x' is now our peak element candidate. 
            # If x exists in the map (even just 1 copy), it can be our middle peak (+1).
            # If x doesn't exist, we over-stepped and must drop the last boundary match (-1).
            if x in count:
                current_length += 1
            else:
                current_length -= 1
                
            # Keep track of the longest valid pattern found
            ans = max(ans, current_length)
            
        return ans