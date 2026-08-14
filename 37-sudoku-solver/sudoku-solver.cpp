class Solution {
public:
   bool isValid(vector<vector<char>> & board , char x , int r,int c){
        for(int i = 0 ; i < 9 ; i++){
            if(i==r)continue;
            if(board[i][c]==x)return false;
        }
        for(int i = 0 ; i < 9 ; i++){
            if(i==c)continue;
            if(board[r][i]==x)return false;
        }
        for(int i = (r/3)*3 ; i < (r/3)*3 + 3; i++ ){
            for(int j = (c/3)*3 ; j < (c/3)*3 + 3 ; j++ ){
                if(i==r&&j==c)continue;
                if(board[i][j]==x)return false;
            }
        }
        return true;
    }

    bool helper(vector<vector<char>> & board , int i , int j){
        if(i >= board.size()) return true;
        if(j == board.size()) return helper(board , i+1 , 0);
        if(board[i][j] == '.'){
            for(int a = 1 ; a <= 9 ; a++){
                if(isValid(board , a + '0' , i , j)){
                    board[i][j] = a + '0';
                    if(helper(board , i , j+1))return true;
                    board[i][j] = '.';
                }
            }
        }
        else return helper(board , i , j+1);
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        if(helper(board , 0 , 0))return;
    }
};