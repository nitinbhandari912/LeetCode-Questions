class Solution {
public:
    void dfs(string& digits,int index,string curr_str,vector<string>& ans,vector<string>& alfa){
        if(index==digits.size()){
            ans.push_back(curr_str);
            return;
        }
        int dignum=digits[index]-'0';
        string letter=alfa[dignum];
        for(int i=0;i<letter.size();i++){
            dfs(digits,index+1,curr_str + letter[i],ans,alfa);
        }
    }
    vector<string> letterCombinations(string digits) {
        int n=digits.size();
        if(digits.empty()) return {};
        vector<string> ans;
        vector<int> vis(26,0);
        vector<string> alfa = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        dfs(digits, 0, "", ans, alfa);
        return ans;
    }
};