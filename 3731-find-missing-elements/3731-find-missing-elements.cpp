class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> answer;
        if (nums.empty()) return answer;
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(nums[i]);
        }
        sort(nums.begin(),nums.end());
        for(int i=nums[0];i<=nums[n-1];i++){
            if(st.find(i)==st.end()){
                answer.push_back(i);
            }
        }
        return answer;
    }
};