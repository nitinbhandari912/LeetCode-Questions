class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if(nums.size()==1) return (double)nums[0];
        double curr_sum=0;
        for(int a=0;a<=k-1;a++){
            curr_sum+=nums[a];
        }
        int n=nums.size();
        double max_sum=curr_sum;
        for(int i=k;i<n;i++){
            curr_sum+=nums[i]-nums[i-k];
            max_sum=max(max_sum,curr_sum);
        }
        return max_sum/k;
    }
};