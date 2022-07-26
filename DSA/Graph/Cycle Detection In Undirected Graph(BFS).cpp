#include<unordered_map>
#include<list>
#include<queue>
bool bfscycle(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited,
             int node){
    
    //for storing parent of each element
    unordered_map<int,int> parent;
    queue<int> q;
    
    q.push(node);
    visited[node] = 1;
    parent[node] = -1;  //for first element parent is -1
    
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        //getting all the neighbours
        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && parent[neighbour] != front && parent[front]!= neighbour){ 
                //neighbour should be visited && its neighbour is not front from which it came && 3rd check for if the parent elemeent is checked again
                //dry run for better understanding
                return true;
            }
            else if(!visited[neighbour]){
                q.push(neighbour);
                visited[neighbour] = 1;
                parent[neighbour] = front;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int, list<int> > adj;
    unordered_map<int, bool> visited;
    
    //adjaceny list
    for(int i=0; i<m; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[v].push_back(u);
        adj[u].push_back(v);

    }
    
    //checking for all elements disconnected
    for(int i=0; i<n; i++){
        if(!visited[i]){
            bool ans = bfscycle(adj, visited, i);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
