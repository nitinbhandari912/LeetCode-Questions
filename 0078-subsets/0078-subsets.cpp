class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> current_subset;
        backtrack(nums, 0, current_subset, res);
        return res;
    }
    
private:
    void backtrack(const vector<int>& nums, int index, vector<int>& current_subset, vector<vector<int>>& res) {
        res.push_back(current_subset);
        for (int i = index; i < nums.size(); ++i) {
            current_subset.push_back(nums[i]);
            backtrack(nums, i + 1, current_subset, res);
            current_subset.pop_back();
        }
    }
};