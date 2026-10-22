#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) {
                k = i;
                break;
            }
        }
        int ans = INT_MAX;
        vector<int> temp1 = nums;
        rotate(temp1.begin(), temp1.begin() + k, temp1.end());
        if (is_sorted(temp1.begin(), temp1.end())) {
            int rotateOnly = k;              
            int revRotateRev = n - k + 2;    
            ans = min(ans, min(rotateOnly, revRotateRev));
        }
        vector<int> temp2 = nums;
        int moves = (k + 1) % n;
        rotate(temp2.begin(), temp2.begin() + moves, temp2.end());
        if (is_sorted(temp2.begin(), temp2.end(), greater<>())) {
            int rotateThenRev = moves + 1;   
            int revThenRotate = n - k;       
            ans = min(ans, min(rotateThenRev, revThenRotate));
        }
        return ans == INT_MAX ? -1 : ans;
    }
};