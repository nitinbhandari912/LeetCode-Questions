class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            vector<int> occ(26,0);
            for(int j=i;j<n;j++){
                occ[s[j]-'a']++;
                if(occ[s[j]-'a']>2){
                    break;
                }
                maxi=max(j-i+1,maxi);
            }
        }
        return maxi;
    }
};