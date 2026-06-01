class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(start>=arr.size() || start<0) return false;
        if (arr[start] < 0) return false;
        if (arr[start] == 0) return true;
        int step = arr[start];
        arr[start]=-arr[start];
        bool left = canReach(arr, start - step);
        bool right = canReach(arr, start + step);
        
        return left || right;
    }
};