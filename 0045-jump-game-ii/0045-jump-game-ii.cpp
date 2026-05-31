class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() <= 1) return 0;
        int jump=0;
        int i=0;
        while(i<nums.size()-1){
            int a=nums[i];
            int maxi=INT_MIN;
            int n=i;
            if (i + a >= nums.size() - 1) {
                jump++;
                break;
            }
            int x=min(a+i+1,(int)nums.size());
            for(int j=i+1;j<x;j++){
                if(maxi<nums[j]+j){
                    maxi=nums[j]+j;
                    n=j;
                }
            }
            i=n;
            jump++;
        }
        return jump;
    }
};