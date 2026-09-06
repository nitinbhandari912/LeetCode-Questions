
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length()) {
            return false;
        }
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == goal[0]) {
                bool isMatch = true;
                for (int j = 0; j < n; j++) {
                    if (s[(i + j) % n] != goal[j]) {
                        isMatch = false;
                        break;
                    }
                }       
                if (isMatch) return true;
            }
        }      
        return false;
    }
};