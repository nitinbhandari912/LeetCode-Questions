class Solution {
public:
    string frequencySort(string s) {
        int n=s.size();
        string a;
        sort(s.begin(),s.end());
        int cnt=0;
        int m=s[0];
        vector<pair<char,int>> vec;
        for(int i=0;i<n;i++){
            if(m==s[i]){
                cnt++;
            }
            else{
                vec.push_back({m,cnt});
                m=s[i];
                cnt=1;
            }
        }
        vec.push_back({m, cnt});
        sort(vec.begin(), vec.end(), [](const pair<char, int>& a, const pair<char, int>& b) {
            return a.second > b.second; // Descending order
        });
        for(int i=0;i<vec.size();i++){
            int b=vec[i].second;
            for(int j=0;j<b;j++){
                a+=vec[i].first;
            }
        }
        return a;
    }
};