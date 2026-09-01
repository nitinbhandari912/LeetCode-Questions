class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int idx_1=0;
        int idx_2=0;
        int n=nums.size();
        if(nums.size()<=2) return (int)nums.size();
        int maxi = nums[0];
        int mini = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxi){
                maxi=nums[i];
                idx_1=i;
            }
            if(nums[i]<mini){
                mini=nums[i];
                idx_2=i;
            }
        }
        int both_front = max(idx_1, idx_2) + 1;
        int both_back = n - min(idx_1, idx_2);
        int front_and_back = min(idx_1, idx_2) + 1 + n - max(idx_1, idx_2);
        return min({both_front, both_back, front_and_back});
    }
};