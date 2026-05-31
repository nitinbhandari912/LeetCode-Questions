class Solution {
public:
    void dfs(vector<int>& candidates,int target,int index,vector<vector<int>>& ans,vector<int>& curr){
        if(target==0){
            ans.push_back(curr);
            return ;
        }
        int n=candidates.size();
        for(int i=index;i<n;i++){
            if(candidates[i]>target) break;
            if(i>index && candidates[i]==candidates[i-1]) continue;
            curr.push_back(candidates[i]);
            dfs(candidates,target-candidates[i],i+1,ans,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> curr;
        dfs(candidates,target,0,ans,curr);
        return ans;
    }
};