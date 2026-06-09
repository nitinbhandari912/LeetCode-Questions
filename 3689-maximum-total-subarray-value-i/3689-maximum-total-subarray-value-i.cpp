class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long maxval=INT_MIN;
        long long minval=INT_MAX;
        for(int i=0;i<nums.size();i++){
            maxval=max((long long)maxval,(long long)nums[i]);
            minval=min((long long)minval,(long long)nums[i]);
        }
        long long diff=maxval-minval;
        long long val=diff*k;
        return val;
    }
};