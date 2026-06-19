class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int> altitude(n+1,0);
        altitude[0]=0;
        int height=0;
        for(int i=0;i<n;i++){
            int num=altitude[i];
            altitude[i+1]=num+gain[i];
            height=max(height,altitude[i+1]);
        }
        return height;
    }
};