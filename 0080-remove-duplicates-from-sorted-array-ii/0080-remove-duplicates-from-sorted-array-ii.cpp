class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int j=0;
        for(auto it : mpp){
            int a=it.first;
            int b=it.second;
            if(b>=2){
                nums[j]=a;
                nums[j+1]=a;
                j+=2;
            }
            else{
                nums[j]=a;
                j++;
            }
        }
        return j;
    }
};