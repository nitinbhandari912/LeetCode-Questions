class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int diffcnt=1;
        int n=candyType.size();
        sort(candyType.begin(),candyType.end());
        for(int i=1;i<n;i++){
            if(candyType[i]!=candyType[i-1]) diffcnt++;
        }
        int eat=n/2;
        if(eat<=diffcnt) return eat;
        else return diffcnt;
    }
};