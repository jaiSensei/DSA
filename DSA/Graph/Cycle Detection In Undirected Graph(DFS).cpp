#include<unordered_map>
#include<list>
#include<queue>

bool dfscycle(unordered_map<int, list<int> > &adj, int parent, unordered_map<int, bool> &visited, int node){
    //mark visited 
    visited[node] = 1;
    
    //neighbour of element
    for(auto neighbour : adj[node]){
        
        //if element is not visited then recusrive bool call neighbour element becomes node and node becomes parent
        if(!visited[neighbour]){
            bool ans = dfscycle(adj, node, visited, neighbour);
            //if returns true
            if(ans){
                return true;
            }
        }
        else if(visited[neighbour] && neighbour!= parent){   //if neighbour is visited and it is not parent element
            return true;  //then cycle present
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
    
    //for loop for disconnected components
    for(int i=0; i<n; i++){
        if(!visited[i]){
            //parent is -1 for first element
            bool ans = dfscycle(adj, -1, visited, i);
            if(ans == 1){
                return "Yes";
            }
        }
    }
    return "No";
}
