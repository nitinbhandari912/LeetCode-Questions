class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> dis;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]==c){
                dis.push_back(i);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            int mini=INT_MAX;
            for(int j=0;j<dis.size();j++){
                int a=abs(dis[j]-i);
                mini=min(mini,a);
            }
            ans.push_back(mini);
        }
        return ans;
    }
};