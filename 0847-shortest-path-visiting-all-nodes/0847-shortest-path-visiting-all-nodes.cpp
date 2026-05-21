class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        queue<pair<int, pair<int, vector<bool>>>> q;
        set<pair<int, vector<bool>>> visited_states;

        for (int i = 0; i < n; i++) {
            vector<bool> initial_checklist(n, false);
            initial_checklist[i] = true;

            q.push({i, {0, initial_checklist}});
            visited_states.insert({i, initial_checklist});
        }

        while (!q.empty()) {
            auto current = q.front();
            q.pop();

            int node = current.first;
            int steps = current.second.first;
            vector<bool> checklist = current.second.second;

            int true_count = 0;
            for (bool val : checklist) {
                if (val == true) true_count++;
            }
            if (true_count == n) {
                return steps;
            }

            for (int neighbor : graph[node]) {
                vector<bool> next_checklist = checklist;
                next_checklist[neighbor] = true;

                pair<int, vector<bool>> next_state = {neighbor, next_checklist};

                if (visited_states.find(next_state) == visited_states.end()) {
                    visited_states.insert(next_state);
                    q.push({neighbor, {steps + 1, next_checklist}});
                }
            }
        }

        return 0;
    }
};