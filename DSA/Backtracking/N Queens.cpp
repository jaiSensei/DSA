void addsolution(vector<vector<int>> &ans, vector<vector<int>> &board,int n){
    vector<int> temp;
    
    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            temp.push_back(board[row][col]);
        }
    }
    ans.push_back(temp);    //unable to understand
}
bool issafe(int row, int col, vector<vector<int>> board,int n){
    //row
    int x = row;
    int y = col;
    while(y >=0){           //only need to check left side of row because we adding elements from left to right
                                // so no elements can be present on right side of queen index
        if(board[x][y] == 1){
            return false;
        }
        y--;
    }
    
    //diagonal
    x = row;               // adding only two directions because left to right reason
    y = col;
    while(x>=0 && y >=0){    //important range
        if(board[x][y] == 1){
            return false;
        }
        y--;     //** imp
        x--;
    }
    
    x = row;
    y = col;
    while(x<n && y >=0){    //important ranhe
        if(board[x][y] == 1){
            return false;
        }
        y--; ///important
        x++;
    }
    return true;
}
void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board,int n){
    
    //base casee
    if(col == n){             //when c exceds the n-1 value 
        addsolution(ans, board, n);
        return;
    }
    
    for(int row=0; row<n; row++){     //increase row of each coloumn
        //checking if we can put a queen in that place
        if(issafe(row,col,board,n)){   
            board[row][col] = 1;   // visited
            solve(col+1, ans, board, n);
            board[row][col] = 0;          //backtracking and removing the visited (only executes when solution is not found)
        }                                 //if solution  is found then addsolution function is execusted and return
    }
}
vector<vector<int>> solveNQueens(int n) {
    
    vector<vector<int>> board (n,vector<int>(n,0));  //creating a board for traversal
    vector<vector<int>> ans; //for storing ans
    
    solve(0,ans,board,n);
    return ans;
}