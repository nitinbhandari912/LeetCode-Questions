class Solution {
public:
    int maxDepth(string s) {
        int max_dep=0;
        int sum=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(') sum++;
            if(s[i]==')'){
                max_dep=max(sum,max_dep);
                sum-=1;
            }
        }
        return max_dep;
    }
};