class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int left=0;
        int right=n-1;
        int vol=0;
        while(left<=right){
            int dif=right-left;
            int h=min(height[left],height[right]);
            vol=max(vol,h*(dif));
            if(height[left]<height[right]) left++;
            else right--;
        }
        return vol;
    }
};