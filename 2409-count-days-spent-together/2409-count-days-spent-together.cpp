#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> daysInMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        auto dateToDays = [&](const string& dateStr) {
            int month = stoi(dateStr.substr(0, 2));
            int day = stoi(dateStr.substr(3, 2));
            int total = day;
            for (int i = 0; i < month - 1; ++i) {
                total += daysInMonth[i];
            }
            return total;
        };
        int start = max(dateToDays(arriveAlice), dateToDays(arriveBob));
        int end = min(dateToDays(leaveAlice), dateToDays(leaveBob));
        return max(0, end - start + 1);
    }
};