class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        int TotalDuration=0;
        int poisonExpiration = 0;
        for(int i=0;i<timeSeries.size();i++){
            if(poisonExpiration>timeSeries[i]){
                TotalDuration+=timeSeries[i]+duration-poisonExpiration;
            }
            else {
                TotalDuration+=duration;
            }
            poisonExpiration=timeSeries[i]+duration;
        }
        return TotalDuration;
    }
};