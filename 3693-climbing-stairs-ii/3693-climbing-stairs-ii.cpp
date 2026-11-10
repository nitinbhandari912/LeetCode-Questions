class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        if (n <= 0) return 0;
        int p1=0;
        int p2=0;
        int p3=0;
        for(int i=1;i<=n;i++){
            int min_prev = p1 + 1;
            if (i >= 2) {
                min_prev = min(min_prev, p2 + 4);
            }
            if (i >= 3) {
                min_prev = min(min_prev, p3 + 9);
            }
            int curr = costs[i - 1] + min_prev;
            p3 = p2;
            p2 = p1;
            p1 = curr;
        }
        return p1;
    }
};