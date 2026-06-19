class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        int altitude=0;
        int height=0;
        for(int i=0;i<n;i++){
            altitude+=gain[i];
            height=max(height,altitude);
        }
        return height;
    }
};