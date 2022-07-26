#include<bits/stdc++.h>
void dfs(int node, unordered_map<int, bool> &visited, stack<int> &s, unordered_map<int, list<int> > &adj){
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            dfs(nbr, visited, s, adj);
        }
    }
    s.push(node);
}
void revdfs(int node, unordered_map<int, bool> &visited, unordered_map<int, list<int> > &adj){
    visited[node] = true;
    
    for(auto nbr : adj[node]){
        if(!visited[nbr]){
            revdfs(nbr, visited, adj);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    //adjacency list
	unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v); //directed graph
    }
    
    //dfs to create topological order
    unordered_map<int, bool> visited;
    stack<int> s;
    for(int i=0; i<v; i++){
        if(!visited[i]){
            dfs(i, visited, s, adj);
        }
    }
    //create a transpose
    unordered_map<int, list<int> > transpose;   //similar to adjacency list
    for(int i=0; i<v; i++){
        visited[i]=0;                           //visited is truwe for all nodes because of last dfs call
        for(auto nbr : adj[i]){
            transpose[nbr].push_back(i);       //reverse order me dal do
        }
    }
    
    //rev dfs
    int count=0;
    while(!s.empty()){
        int top = s.top();
        s.pop();
        
        if(!visited[top]){                  //one element is taken to start and remaining get visited = true in revdfs call
            count++;                        //sp the number of times this if statement is executed count increases of the no of SCCs
            revdfs(top, visited, transpose );
        }
    }
    return count;
}