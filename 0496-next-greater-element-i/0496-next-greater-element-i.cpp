class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<int> ans(n,-1);
        for(int i=0;i<n;i++){
            int num=nums1[i];
            int j=0;
            int val=0;
            bool flag=false;
            while(j<m){
                if(num==nums2[j]){
                    val=nums2[j];
                    flag=true;
                }
                if(flag==true && val<nums2[j]){
                    ans[i]=nums2[j];
                    break;
                }
                j++;
            }
        }
        return ans;
    }
};