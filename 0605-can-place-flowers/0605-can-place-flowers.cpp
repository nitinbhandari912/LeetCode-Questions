class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0) return true;
        int i=0;
        while(i<flowerbed.size()){
            if(flowerbed[i]==1) i+=2;
            else{
                bool left=(i==0 || flowerbed[i - 1] == 0);
                bool right=(i==flowerbed.size()-1 || flowerbed[i + 1] == 0);
                if(left && right) {
                    n--;
                    if(n==0) return true;
                    i+=2;
                }
                else i++;
            }
        }
        return n<0;
    }
};