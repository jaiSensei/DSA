bool isSolve(int newx, int newy, vector < vector < int >> & arr,vector<vector<bool> > &vis,int n){
    if((newx>=0 && newx < n ) && (newy >=0 && newy < n) && vis[newx][newy] != 1 && arr[newx][newy] == 1){ 
        return true;
    }
    else{
        return false;
    }
}
void solve(int x, int y,vector < vector < int >> & arr, int n, vector<string> &ans ,
           vector<vector<bool> > &vis, string path ){
        
        //base case
        if( x == n-1 && y == n-1){       //when destination is reached
            ans.push_back(path);          //path will have complete ans push it in ans
            return;
        }
        
        
        vis[x][y]=1;    //was present in every if statement hence out of if statements
                        //any one of the following if statments will be executed hence visited can be marked 1
        //down          
        if(isSolve(x+1,y,arr,vis,n)){
            solve(x+1,y,arr,n,ans,vis,path + 'D');              //for path no need to pop back it is added here not pushback
        }                                                       //value of only path will backtracked
        //left
        if(isSolve(x,y-1,arr,vis,n)){
            solve(x,y-1,arr,n,ans,vis,path + 'L');
        }
        //right
        if(isSolve(x,y+1,arr,vis,n)){
            solve(x,y+1,arr,n,ans,vis,path + 'R');
        }
        //up
        if(isSolve(x-1,y,arr,vis,n)){
            solve(x,y-1,arr,n,ans,vis,path + 'U');
        }
        vis[x][y]=0;   ///***important was present in every if statement when backtracking the visited paths must be marked 
                        //unvisited
    }
vector < string > searchMaze(vector < vector < int >> & arr, int n) {
    vector<string> ans;
    vector<vector<bool> > visited (n,vector<bool> (n,0));  ///**intiallising every element as 0
    string path = "";
    if(arr[0][0] == 0){      //if first box has 0 value 
            return ans;
        }
    
    solve(0,0,arr,n, ans, visited, path);
    return ans;
}