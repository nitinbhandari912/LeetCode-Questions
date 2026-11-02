class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int mid=0;
        if(n%2==0){
            mid=n/2;
        }
        else{
            mid=(n+1)/2;
        }
        int moves=0;
        for(int i=0;i<mid;i++){
            moves+=nums[mid-1]-nums[i];
        }
        for(int i=mid;i<n;i++){
            moves+=nums[i]-nums[mid-1];
        }
        return moves;
    }
};