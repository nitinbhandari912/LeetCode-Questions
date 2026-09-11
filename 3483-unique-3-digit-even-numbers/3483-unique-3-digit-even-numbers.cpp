class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> count(10, 0);
        for (int digit : digits) {
            count[digit]++;
        }
        int result = 0;
        for (int num = 100; num <= 998; num += 2) {
            int hundreds = num / 100;
            int tens = (num / 10) % 10;
            int units = num % 10;
            count[hundreds]--;
            count[tens]--;
            count[units]--;
            if (count[hundreds] >= 0 && count[tens] >= 0 && count[units] >= 0) {
                result++;
            }
            count[hundreds]++;
            count[tens]++;
            count[units]++;
        }
        return result;
    }
};