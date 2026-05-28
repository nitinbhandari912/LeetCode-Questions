#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        vector<vector<int>> trie;
        vector<int> bestIndex;
        
        auto createNode = [&]() {
            trie.push_back(vector<int>(26, -1));
            bestIndex.push_back(-1);
            return trie.size() - 1;
        };
        
        int root = createNode();
        
        int globalMinIdx = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < wordsContainer[globalMinIdx].size()) {
                globalMinIdx = i;
            }
        }
        bestIndex[root] = globalMinIdx;

        for (int i = 0; i < wordsContainer.size(); i++) {
            string word = wordsContainer[i];
            reverse(word.begin(), word.end());
            
            int curr = root;
            
            if (bestIndex[curr] == -1 || 
                wordsContainer[i].size() < wordsContainer[bestIndex[curr]].size()) {
                bestIndex[curr] = i;
            }
            
            for (char c : word) {
                int idx = c - 'a';
                if (trie[curr][idx] == -1) {
                    trie[curr][idx] = createNode();
                }
                curr = trie[curr][idx];
                
                if (bestIndex[curr] == -1 || 
                    wordsContainer[i].size() < wordsContainer[bestIndex[curr]].size()) {
                    bestIndex[curr] = i;
                }
            }
        }

        vector<int> ans;
        for (int i = 0; i < wordsQuery.size(); i++) {
            string query = wordsQuery[i];
            reverse(query.begin(), query.end());
            
            int curr = root;
            int lastValidIndex = bestIndex[root];
            
            for (char c : query) {
                int idx = c - 'a';
                if (trie[curr][idx] == -1) {
                    break;
                }
                curr = trie[curr][idx];
                lastValidIndex = bestIndex[curr];
            }
            ans.push_back(lastValidIndex);
        }

        return ans;
    }
};