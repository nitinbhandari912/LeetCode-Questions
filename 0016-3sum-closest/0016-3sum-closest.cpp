class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        int closest_sum=nums[0]+nums[1]+nums[2];
        sort(nums.begin(),nums.end());
        for(int mid=1;mid<n-1;mid++){
            int left=0;
            int right=n-1;
            while(left<mid && right>mid){
                int current_sum=nums[left]+nums[right]+nums[mid];
                if(abs(current_sum-target)<abs(closest_sum-target)){
                    closest_sum=current_sum;
                }
                if(current_sum<target){
                    left++;
                }
                else right--;
            }
        }
        return closest_sum;
    }
};