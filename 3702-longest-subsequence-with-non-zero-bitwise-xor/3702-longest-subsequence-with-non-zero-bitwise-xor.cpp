class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        int zeroCount = 0;
        int n = nums.size();
        for (int num : nums) {
            totalXor ^= num;
            if (num == 0) {
                zeroCount++;
            }
        }
        if (zeroCount == n) {
            return 0;
        }
        if (totalXor != 0) {
            return n;
        }
        return n-1;
    }
};