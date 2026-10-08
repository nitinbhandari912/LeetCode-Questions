class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<int> st;
        vector<int> remove;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(st.size()==1){
                    int idx=st.top();
                    remove.push_back(idx);
                    remove.push_back(i);
                }
                st.pop(); 
            }
        }
        sort(remove.begin(),remove.end());
        string ans="";
        int j=0;
        for(int i=0;i<s.size();i++){
            if(j>=remove.size()){
                ans+=s[i];
                continue;
            }
            else if(remove[j]==i){
                j++;
                continue;
            }
            ans+=s[i];
        }
        return ans;
    }
};