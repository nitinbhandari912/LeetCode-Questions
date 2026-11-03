class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int moves=0;
        for(int i=0;i<nums.size();i++){
            moves+=nums[n-1]-nums[i];
        }
        return moves;
    }
};