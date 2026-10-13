class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long sum=0;
        long long sub=0;
        for(int i=0;i<n;i++){
           nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        if(n%2==0){
            for(int i=0;i<n/2;i++){
                sub+=(long long)nums[i]*nums[i];
            }
            for(int i=n/2;i<n;i++){
                sum+=(long long)nums[i]*nums[i];
            }
        }
        else{
            for(int i=0;i<(n-1)/2;i++){
                sub+=(long long)nums[i]*nums[i];
            }
            for(int i=(n-1)/2;i<n;i++){
                sum+=(long long)nums[i]*nums[i];
            }
        }
        return sum-sub;
    }
};