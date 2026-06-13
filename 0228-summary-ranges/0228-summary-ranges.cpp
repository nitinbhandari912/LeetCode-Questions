class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if (nums.empty()) return ans;
        int ancor = 0;
        for (int i = 1; i < nums.size(); i++) {
            if ((long long)nums[i] != (long long)nums[i-1] + 1) {
                if (ancor == i - 1) {
                    ans.push_back(to_string(nums[ancor]));
                }
                else {
                    ans.push_back(to_string(nums[ancor]) + "->" + to_string(nums[i-1]));
                }
                ancor = i;
            }
        } 
        if (ancor == nums.size() - 1) {
            ans.push_back(to_string(nums[ancor]));
        }
        else {
            ans.push_back(to_string(nums[ancor]) + "->" + to_string(nums[nums.size() - 1]));
        }
        return ans;
    }
};