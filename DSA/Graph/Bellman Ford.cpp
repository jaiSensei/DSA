int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    
    vector<int> dist(n+1, 1e9);  ///intiallizing it with a big number
    dist[src] = 0;
    
    for(int i=1; i<=n; i++){   ///done n-1 times
        
        for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e9 && (dist[u]+wt) < dist[v]){       //if parent element is not infinite other elements will also get 
                dist[v] = dist[u] + wt;                         // non infinte numbers
            }
        }
    }
    
    bool flag = 0;
    //checking 1 more time to check if it is -ve cycle or not
    for(int j=0; j<m; j++){
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            
            if(dist[u] != 1e9 && (dist[u]+wt) < dist[v]){
                flag = 1;
            }
        }
    if(flag == 0){
        return dist[dest];
    }
    return -1;
}