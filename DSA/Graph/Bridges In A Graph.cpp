#include<bits/stdc++.h>
void dfs(int node, int parent, int &timer, unordered_map<int, list<int> > &adj, vector<int> &dsc, vector<int> &low, unordered_map<int, bool> &visited,  vector<vector<int>> &result){
    
    visited[node] = true;
    dsc[node] = low[node] = timer++;    //increase timer and store
    
    for(auto nbr: adj[node]){
        if(nbr == parent){     //if parent no need to do anything
            continue;
        }
        if(!visited[nbr]){
            dfs(nbr, node, timer, adj, dsc, low, visited, result);    //calculate for neighbour node
            low[node] = min(low[node], low[nbr]);   //low can be from one side or other side too
            
            if(low[nbr] > dsc[node]){      //that means it is calculated only from one path as neighbour comes after it has higher low
                vector<int> ans;
                ans.push_back(node);
                ans.push_back(nbr);
                result.push_back(ans);
            }
        }
        else{
            //back edge
            low[node] = min(low[node], dsc[nbr]);     //when back edge is formed then (0 and 1 example)
        }
    }
}
vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    
    unordered_map<int, list<int> > adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> dsc(v);  //discovery time
    vector<int> low(v);  //lowest discovery time
    int parent = -1;
    unordered_map<int, bool> visited;
    int timer = 0;
    
    
    for(int i=0; i<v; i++){
        dsc[i] = -1;
        low[i] = -1;
    }
    
    vector<vector<int>> result;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, parent, timer, adj, dsc, low, visited, result);
        }
    }
    return result;
    
}