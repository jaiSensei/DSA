




//time complexity = 9^(n)    n = no of empty spaces
//space c = n*n





bool isSafe(int row, int col, vector<vector<int>> &board, int val){
    int n = board.size();
    
    for(int i=0; i<n; i++){
        //row
        if(board[row][i] == val){
            return false;
        }
        //coloumn
        else if(board[i][col] == val){
            return false;
        }
        else if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val){       //remeber this
            return false;
        }
        
    }
    return true;
}
bool solver(vector<vector<int>>& board){
    
    for(int row=0; row<board.size(); row++){
        for(int col=0; col < board.size(); col++){
            //if empty
            if(board[row][col] == 0){
                //iterate through all the values
                for(int i=0; i<=9; i++){
                    //check if it safe to put the value
                    if(isSafe(row, col, board, i)){
                        //update the value
                        board[row][col] = i;


                        //check if further solution exists
                        bool solution = solver(board);
                        
                        //if solution exists
                        if(solution){
                            return true;
                        }
                        else{
                            //if solution doees not exist then
                            //backtrack (update the value to 0 ie empty)
                            board[row][col] = 0;
                        }
                    }
                }
                //if answer not found
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<int>>& sudoku)
{
	solver(sudoku);
}