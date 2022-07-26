#include<unordered_map>
#include<list>
bool dfscycle(unordered_map<int,list<int>> &adj, unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsvisited, int node ){
    
    visited[node] = 1;
    dfsvisited[node] = 1;     //element visited and call open
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour]){                    //if element is not visited then recursive call for that element
            bool cycledetected = dfscycle(adj, visited, dfsvisited, neighbour);
            if(cycledetected){
                return true;
            }
        }
        else if(dfsvisited[neighbour] && visited[neighbour]){      //this is executed when if statement is not executed
            //visited                                              //therefore we are still updating visited and dfsvisited and this is not executed
            return true;                                            // because that element,s neighbour was not visited before
        }
    }
    dfsvisited[node] = 0;   ///backtracking because call for the element is closed
    return false;  //return false;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  unordered_map<int,list<int>> adj;
    
    //adjacency list 
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        //directe graph
        adj[u].push_back(v);
        
    }
    
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsvisited;    //**vvery important true when call for element is open 0 when call is closed 
    
    //for loop for all disconnected componnents
    for(int i=1; i<=n; i++){
        if(!visited[i]){
            bool cyclepresent = dfscycle(adj, visited, dfsvisited, i);
            if(cyclepresent){
                return true;
            }
        }
    }
    return false;
    
}