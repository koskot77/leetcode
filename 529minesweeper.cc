// simulate clicks according to the rules by recursive calls for spases around, update the retval
class Solution {
public:
    bool valid(vector<vector<char>>& board, vector<int>& click){
        if( click[0] < 0 || click[1] < 0 || click[0] >= board.size() || click[1] >= board[0].size() )
            return false;
        return true;
    }

    int mines_around(vector<vector<char>>& board, vector<int>& click){
        int cnt = 0;
            vector<int> next_click(click);
            next_click[0] = click[0]+1;
            next_click[1] = click[1];
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0]-1;
            next_click[1] = click[1];
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0];
            next_click[1] = click[1]+1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0];
            next_click[1] = click[1]-1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0]+1;
            next_click[1] = click[1]+1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0]-1;
            next_click[1] = click[1]-1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0]+1;
            next_click[1] = click[1]-1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
            next_click[0] = click[0]-1;
            next_click[1] = click[1]+1;
            if( valid(board, next_click) && board[next_click[0]][next_click[1]] == 'M' ) cnt++;
         return cnt;        
    }
    bool helper(vector<vector<char>>& board, vector<int>& click, bool check) {
        if( click[0] < 0 || click[1] < 0 || click[0] >= board.size() || click[1] >= board[0].size() ) return false;
        if( board[click[0]][click[1]] >= '1' && board[click[0]][click[1]] < '9' ) return false;
        if( board[click[0]][click[1]] == 'B' ) return false;

        if( board[click[0]][click[1]] == 'M' ){
            if(!check) board[click[0]][click[1]] = 'X';
            return true;
        }
        int cnt = 0;
        if( board[click[0]][click[1]] == 'E'){
            int qwe = mines_around(board, click);
            board[click[0]][click[1]] = ((const char[]){'B','1','2','3','4','5','6','7','8'})[qwe];
            if( qwe > 0 ) return false;
            vector<int> next_click(click);
            next_click[0] = click[0]+1;
            next_click[1] = click[1];
            if( helper(board, next_click, true) ) cnt++;
            next_click[0] = click[0]-1;
            next_click[1] = click[1];
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0];
            next_click[1] = click[1]+1;
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0];
            next_click[1] = click[1]-1;
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0]+1;
            next_click[1] = click[1]+1;
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0]-1;
            next_click[1] = click[1]-1;
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0]+1;
            next_click[1] = click[1]-1;
            if( helper(board, next_click, true) ) cnt++;;
            next_click[0] = click[0]-1;
            next_click[1] = click[1]+1;
            if( helper(board, next_click, true) ) cnt++;;
        }
        return false;
    }
    
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        helper(board, click, false);
        return board;
    }
};
