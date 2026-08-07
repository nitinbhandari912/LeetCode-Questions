class Solution {
public:
    int nrow[4]={-1,0,0,1};
    int ncol[4]={0,-1,1,0};
    bool dfs(vector<vector<char>>& board,string& word,int row,int col,int i){
        if(i==word.size()) return true;
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[i]) {
            return false;
        }
        char temp = board[row][col];
        board[row][col] = '*';
        for(int j=0;j<4;j++){
            int r=row+nrow[j];
            int c=col+ncol[j];
            if (dfs(board, word, r, c, i + 1)) {
                return true; 
            }
        }
        board[row][col] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};