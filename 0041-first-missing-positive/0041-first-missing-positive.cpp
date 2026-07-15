class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int maxi=0;
        set<int> st;
        for(int i = 0; i < nums.size(); i++){
            if (nums[i] > 0) {
                maxi = max(maxi, nums[i]);
                st.insert(nums[i]); 
            }
        }
        int left = 1;
        for(auto it :st){
            if (it !=left) return left;
            left++;
        }
        return maxi+1;
    }
};