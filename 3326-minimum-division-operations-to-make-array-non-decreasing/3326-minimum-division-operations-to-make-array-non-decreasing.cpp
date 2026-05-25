#include <cmath>
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 0;
        int cnt=0;
        for(int i=n-1;i>=1;i--){
            if(nums[i]>=nums[i-1]) continue;
            else{
                int a=nums[i-1];
                int smallest_factor = a;
                for (int j = 2; j * j <= a; j++) {
                    if (a % j == 0) {
                        smallest_factor = j;
                        cnt++;
                        break;
                    }
                }
                nums[i-1] = smallest_factor;
            }
            if (nums[i - 1] > nums[i]) {
                return -1;
            }
        }
        return cnt;
    }
};