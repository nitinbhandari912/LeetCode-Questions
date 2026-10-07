class Solution {
public:
    bool isValid(const string& s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
    void rec(set<string>& st, int index, int left_rem, int right_rem, string s) {
        if (left_rem == 0 && right_rem == 0) {
            if (isValid(s)) {
                st.insert(s); 
            }
            return;
        }
        for (int i = index; i < s.size(); i++) {
            if (i > index && s[i] == s[i - 1]) continue;
            if (s[i] == '(' && left_rem > 0) {
                string temp = s;
                temp.erase(i, 1);
                rec(st, i, left_rem - 1, right_rem, temp);
            } 
            else if (s[i] == ')' && right_rem > 0) {
                string temp = s;
                temp.erase(i, 1);
                rec(st, i, left_rem, right_rem - 1, temp);
            }
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int left_rem = 0, right_rem = 0;
        for (char c : s) {
            if (c == '(') {
                left_rem++;
            } else if (c == ')') {
                if (left_rem > 0) {
                    left_rem--; 
                } else {
                    right_rem++; 
                }
            }
        }
        set<string> st;
        rec(st, 0, left_rem, right_rem, s);
        return vector<string>(st.begin(), st.end());
    }
};