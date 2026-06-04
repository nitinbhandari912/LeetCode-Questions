class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.size()!=t.size()) return false;
        vector<pair<char,char>> vec;
        for(int i=0;i<s.size();i++){
            vec.push_back({s[i],t[i]});
        }
        for(int i=0;i<vec.size();i++){
            for(int j=0;j<vec.size();j++){
                if(i==j) continue;
                if(vec[i].first==vec[j].first){
                    if(vec[i].second!=vec[j].second) return false;
                }
                if(vec[i].second==vec[j].second){
                    if(vec[i].first!=vec[j].first) return false;
                }
            }
        }
        return true;
    }
};