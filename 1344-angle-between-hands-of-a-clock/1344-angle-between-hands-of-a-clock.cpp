class Solution {
public:
    double angleClock(int hour, int minutes) {
        double H=30*hour;
        double M=5.5*minutes;
        if(abs(H-M)<180) return abs(H-M);
        return 360-abs(H-M);
    }
};