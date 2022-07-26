vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {
   vector<int> ans[n];
   //ans[n] declares n vectors ie vector[0], vector[1], vector[0], and each can have values like vector
    for(int i=0; i<m; i++){
        //edges stores data in 2 cols 
        int u = edges[i][0];
        int v = edges[i][1];
        
        //undirection hence two pushbacks
        ans[u].push_back(v);
        ans[v].push_back(u);

    }
    vector<vector<int> > adj(n);
    for(int i=0; i<n; i++){
        adj[i].push_back(i);     //question had same elements in answer
        
        for(int j=0; j<ans[i].size(); j++){
            adj[i].push_back(ans[i][j]);    //push all element having edge connections
        }
    }
    return adj;
}