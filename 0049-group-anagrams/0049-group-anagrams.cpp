class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> result;
        unordered_map<string, vector<string>> mp;
        for(int i=0;i<n;i++){
            string original = strs[i];
            string sorted_str = strs[i];
            sort(sorted_str.begin(), sorted_str.end());
            mp[sorted_str].push_back(original);
        }
        for(auto it : mp){
            result.push_back(it.second);
        }
        return result;
    }
};