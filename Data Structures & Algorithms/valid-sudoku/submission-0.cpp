class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> column[9];
        unordered_set<char> boxes[9];
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                char num=board[i][j];
                int box=(i/3)*3 +(j/3);
                if(row[i].count(num) ||column[j].count(num)||boxes[box].count(num)){
                    return false;
                }
                row[i].insert(num);
                column[j].insert(num);
                boxes[box].insert(num);
            }
        }
        return true;
    }
};
