void dfs(unordered_map<int, list<int> > &adj, unordered_map<int, bool> &visited, vector<int> &component, int node){
    
    //adding the first node data
    component.push_back(node);
    visited[node] = 1;
    
    //recursive iteration for the graph
    for(auto i:adj[node]){
        if(!visited[i]){
            dfs(adj, visited, component, i);   //here i is not integers it is elements of the adj list(auto is used)
        }
    }
}


vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int, bool> visited;
    unordered_map<int, list<int> > adj;
    
    //creating adjency list
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);

    }
    
    //because disconnected graph and answer is needed to be shown separetly for diffeerent component
    vector<vector<int>> ans;
    
    //calling all elements because the graph is discontinuos
    for(int i=0; i<V; i++){
        if(!visited[i]){
            vector<int> component;
            dfs(adj, visited, component, i);
            ans.push_back(component);
        }
    }
    return ans;
}