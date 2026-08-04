class Solution {
public:
    int countStreak(string& sequence, string& word, int i) {
        if (i + word.size() > sequence.size()) {
            return 0;
        }
        for (int k = 0; k < word.size(); k++) {
            if (sequence[i + k] != word[k]) {
                return 0;
            }
        }
        return 1 + countStreak(sequence, word, i + word.size());
    }
    int maxRepeating(string sequence, string word) {
        int max_count = 0;
        for (int i = 0; i < sequence.size(); i++) {
            int current_streak = countStreak(sequence, word, i);
            max_count = max(max_count, current_streak);
        }
        return max_count;
    }
};