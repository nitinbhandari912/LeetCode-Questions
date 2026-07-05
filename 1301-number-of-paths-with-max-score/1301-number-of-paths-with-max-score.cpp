class Solution {
public:
    int nrow[3] = {-1, 0, -1};
    int ncol[3] = {0, -1, -1};
    int MOD = 1000000007;
    pair<int, int> dfs(vector<string>& board, int r, int c, vector<vector<pair<int, int>>>& memo) {
        if (board[r][c] == 'E') {
            return {0, 1}; 
        }   
        if (memo[r][c].first != -2) {
            return memo[r][c];
        }
        int current_max_score = -1;
        int current_paths = 0;
        for (int i = 0; i < 3; i++) {
            int next_r = r + nrow[i];
            int next_c = c + ncol[i];
            if (next_r >= 0 && next_c >= 0 && board[next_r][next_c] != 'X') {
                pair<int, int> next_step = dfs(board, next_r, next_c, memo);
                int next_score = next_step.first;
                int next_path_count = next_step.second;
                if (next_score != -1) {
                    if (next_score > current_max_score) {
                        current_max_score = next_score;
                        current_paths = next_path_count;
                    } else if (next_score == current_max_score) {
                        current_paths = (current_paths + next_path_count) % MOD;
                    }
                }
            }
        }        
        if (current_max_score != -1) {
            int val = (board[r][c] == 'S') ? 0 : (board[r][c] - '0');
            current_max_score += val;
        }
        return memo[r][c] = {current_max_score, current_paths};
    }
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int, int>>> memo(n, vector<pair<int, int>>(n, {-2, -1}));
        pair<int, int> result = dfs(board, n - 1, n - 1, memo);
        if (result.first == -1) {
            return {0, 0};
        }
        return {result.first, result.second};
    }
};