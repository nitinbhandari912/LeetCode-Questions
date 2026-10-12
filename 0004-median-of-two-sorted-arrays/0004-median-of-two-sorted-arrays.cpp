class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;
        int a=nums1.size();
        int b=nums2.size();
        int i=0;
        int j=0;
        while(i<a && j<b){
            if(nums1[i]<nums2[j]){
                arr.push_back(nums1[i]);
                i++;
            }
            else{
                arr.push_back(nums2[j]);
                j++;
            }
        }
        while(i<a){
            arr.push_back(nums1[i]);
            i++;
        }
        while(j<b){
            arr.push_back(nums2[j]);
            j++;
        }
        int n=nums1.size()+nums2.size();
        if(n%2==1) return arr[n/2];
        return (double)((double)(arr[n/2]) + (double)(arr[n/2-1]))/2.0;
    }
};