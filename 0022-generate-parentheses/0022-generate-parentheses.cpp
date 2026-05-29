class Solution {
public: 
    void dfs(int n,vector<string>& ans,int open_cnt,int close_cnt,string s){
        if(n*2==s.size()){
            ans.push_back(s);
            return ;
        }
        if(open_cnt<n){
            dfs(n,ans,open_cnt+1,close_cnt,s+'(');
        }
        if(close_cnt<open_cnt){
            dfs(n,ans,open_cnt,close_cnt+1,s+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(n,ans,0,0,"");
        return ans;
    }
};