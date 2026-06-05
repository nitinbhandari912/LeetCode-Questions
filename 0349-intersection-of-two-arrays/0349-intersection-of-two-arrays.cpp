class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        set<int> st(nums1.begin(),nums1.end());
        set<int> st1(nums2.begin(),nums2.end());
        vector<int> ans;
        auto it =st.begin();
        auto it1 =st1.begin();
        while(it!=st.end() && it1!=st1.end()){
            if(*it==*it1){
                int num=*it;
                ans.push_back(num);
                ++it;
                ++it1;
            }
            if(*it>*it1){
                ++it1;
            }
            else if(*it<*it1){
                ++it;
            }

        }
        return ans;
    }
};