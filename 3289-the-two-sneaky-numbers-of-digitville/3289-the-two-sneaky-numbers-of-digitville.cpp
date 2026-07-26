class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,int> mpp;
        for(int i=0;i<nums.size();i++){
            mpp[nums[i]]++;
        }
        vector<int> vec;
        for(auto it :mpp){
            if(it.second==2){
                vec.push_back(it.first);
            }
        }
        return vec;
    }
};