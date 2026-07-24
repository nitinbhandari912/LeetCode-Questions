class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> spiral(n,vector<int>(n,0));
        int cnt=1;
        int top = 0, bottom = n - 1;
        int left = 0, right = n - 1;
        while(top<=bottom && left<=right){
            for (int j = left; j <= right; j++) {
                spiral[top][j] = cnt++;
            }
            top++;
            for(int j=top;j<=bottom;j++){
                spiral[j][right]=cnt++;
            }
            right--;
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    spiral[bottom][j] = cnt++;
                }
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    spiral[i][left] = cnt++;
                }
                left++;
            }
        }
        return spiral;
    }
};