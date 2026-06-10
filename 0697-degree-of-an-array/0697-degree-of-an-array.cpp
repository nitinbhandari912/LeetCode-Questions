class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        int fr=0;
        vector<int> val;
        for(auto it :mpp){
            if(it.second>fr){
                fr=it.second;
            }
        }
        for(auto it:mpp){
            if(it.second==fr){
                val.push_back(it.first);
            }
        }
        int low=-1;
        int high=-1;
        int maxi=INT_MAX;
        for(int j=0;j<val.size();j++){
            for(int i=0;i<nums.size();i++){
                if(low==-1 && nums[i]==val[j]){
                    low=i;
                }
                if(nums[i]==val[j]) high=i;
            }
            maxi=min(maxi,high-low+1);
            low=-1;
            high=-1;
        }
        return maxi;
    }
};