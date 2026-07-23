class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n=nums.size();
        int n1=2*n;
        vector<int> num(n1,0);
        for(int i=0;i<n;i++){
            num[i]=nums[i];
            num[i+n]=nums[i];
        }
        return num;
    }
};