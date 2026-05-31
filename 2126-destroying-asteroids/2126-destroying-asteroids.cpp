class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long sum=mass;
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        for(int i=0;i<n;i++){
            if(sum>=asteroids[i]){
                sum+=(long long)asteroids[i];
            }
            else if(asteroids[i]>sum) return false;
        }
        return true;
    }
};