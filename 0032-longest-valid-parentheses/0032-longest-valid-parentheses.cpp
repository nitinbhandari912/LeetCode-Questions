class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size()==0) return 0;
        stack<int> st;
        st.push(-1);
        int maxLength = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else{
                st.pop();
                if(st.empty()) st.push(i);
                else{
                    int currentLength = i - st.top();
                    maxLength = max(maxLength, currentLength);
                }
            }
        }
        return maxLength;
    }
};