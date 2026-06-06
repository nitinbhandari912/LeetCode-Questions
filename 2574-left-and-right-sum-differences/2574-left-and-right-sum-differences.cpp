class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> ans;
        int leftSum=0;
        int rightSum=0;
        for(int i=1;i<nums.size();i++){
            rightSum+=nums[i];
        }
        ans.push_back(abs(rightSum-leftSum));
        for(int i=1;i<nums.size();i++){
            leftSum+=nums[i-1];
            rightSum-=nums[i];
            ans.push_back(abs(leftSum-rightSum));
        }
        return ans;
    }
};