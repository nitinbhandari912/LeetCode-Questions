class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> val;
        string st="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                st+=s[i];
            }
            else{
                val.push_back(st);
                st="";
            }
        }
        val.push_back(st);
        if (pattern.size() != val.size()) {
            return false;
        }
        vector<pair<string,char>> patval;
        for(int i=0;i<pattern.size();i++){
            patval.push_back({val[i],pattern[i]});
        }
        for(int i=0;i<pattern.size();i++){
            char ch=patval[i].second;
            string a=patval[i].first;
            for(int j=0;j<pattern.size();j++){
                if(i == j) continue;
                if(ch==patval[j].second && i!=j){
                    if(a!=patval[j].first){
                        return false;
                    }
                }
                if(a == patval[j].first) {
                    if(ch != patval[j].second) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};