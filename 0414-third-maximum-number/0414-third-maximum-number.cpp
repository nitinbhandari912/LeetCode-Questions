class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> st(nums.begin(), nums.end());
        if(st.size()<3){
            return *st.rbegin();
        }
        auto it=st.rbegin();
        advance(it,2);
        return *it;
    }
};