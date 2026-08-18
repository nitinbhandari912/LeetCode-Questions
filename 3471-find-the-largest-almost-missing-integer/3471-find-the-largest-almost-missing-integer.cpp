class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n=nums.size();
        if (k == n) {
            int maxi = 0;
            for(int i = 0; i < n; i++){
                maxi = max(maxi, nums[i]);
            }
            return maxi;
        }
        if (k == 1) {
            int freq[51] = {0}; 
            for(int i = 0; i < n; i++) {
                freq[nums[i]]++;
            }
            for(int i = 50; i >= 0; i--) {
                if(freq[i] == 1) return i;
            }
            return -1;
        }
        int a = nums[0];
        int b = nums[n-1];
        int cnt_a = 0;
        int cnt_b = 0;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == a) cnt_a++;
            if(nums[i] == b) cnt_b++;
        }
        if (cnt_a >= 2 && cnt_b == 1) return b;
        if (cnt_a == 1 && cnt_b >= 2) return a;
        if (cnt_a >= 2 && cnt_b >= 2) return -1; 
        return max(a, b);
    }
};