class Solution {
public:
    void dfs(int index,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>& str){
        if(target==0){
            ans.push_back(str);
            return ;
        }
        if (target < 0 || index >= candidates.size()) {
            return;
        }
        int n=candidates.size();
        str.push_back(candidates[index]);
        dfs(index, candidates, target - candidates[index], ans,str);
        str.pop_back();
        dfs(index + 1, candidates, target, ans,str);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> str;
        dfs(0, candidates, target, ans,str);
        return ans;
    }
};