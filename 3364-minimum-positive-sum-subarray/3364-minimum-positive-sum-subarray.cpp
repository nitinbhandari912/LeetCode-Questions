class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n && (j - i + 1) <= r; j++) {
                sum += nums[j];
                if ((j - i + 1) >= l && sum > 0) {
                    min_sum = min(min_sum, sum);
                }
            }
        }
        return min_sum == INT_MAX ? -1 : min_sum;
    }
};