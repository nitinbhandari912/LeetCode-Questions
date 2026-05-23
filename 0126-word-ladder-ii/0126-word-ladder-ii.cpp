class Solution {
    unordered_map<string, int> mpp; // Stores the shortest distance to each word
    vector<vector<string>> ans;
    string b;

    void dfs(string word, vector<string>& seq) {
        if (word == b) {
            reverse(seq.begin(), seq.end());
            ans.push_back(seq);
            reverse(seq.begin(), seq.end()); // Backtrack reverse for other branches
            return;
        }

        int steps = mpp[word];
        int sz = word.size();

        // Check all potential parents that are exactly 1 step closer to beginWord
        for (int i = 0; i < sz; i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mpp.find(word) != mpp.end() && mpp[word] == steps - 1) {
                    seq.push_back(word);
                    dfs(word, seq);
                    seq.pop_back(); // Backtrack
                }
            }
            word[i] = original;
        }
    }

public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        queue<string> q;
        q.push(beginWord);
        b = beginWord;
        mpp[beginWord] = 1;
        st.erase(beginWord);
        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int steps = mpp[word];

            if (word == endWord) break;
            for (int i = 0; i < word.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.count(word)) {
                        q.push(word);
                        st.erase(word);
                        mpp[word] = steps + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mpp.find(endWord) != mpp.end()) {
            vector<string> seq;
            seq.push_back(endWord);
            dfs(endWord, seq);
        }

        return ans;
    }
};