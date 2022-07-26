#include<bits/stdc++.h>
using namespace std;
void dfs(int node, int parent, int timer, vector<int> &dsc, vector<int> &low,unordered_map<int, bool> &visited,vector<int> &ap,unordered_map<int, list<int> > &adj){

    visited[node] = true;
    dsc[node] = low[node] = timer++;

    int child=0;
    for(auto nbr : adj[node]){
        if(nbr == parent){
            continue;
        }
        if(!visited[nbr]){
            //not visited
            
            //find all connected in graph
            dfs(nbr, node, timer, dsc, low, visited, ap, adj);
            low[node] = min(low[nbr], low[node]); //find lowest discovery time (nbr side se bhi aa sakata hai path aur node side se bhi lowest find karna hai)
            if(low[nbr] >= dsc[node] && parent != -1){    //condition to check AP 
                ap[node] = true;
            }
            child++;   //count child if node is removed
        }
        else{
            low[node] = min(low[node], dsc[nbr]);   //if visited
        }
    }
    if(parent == -1 && child > 1){      //node has parent -1 so to check if it is AP
        ap[node] = true;
    }
}
int main(){
    vector<pair<int,int>> edges;

    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(0,3));
    edges.push_back(make_pair(0,4));
    edges.push_back(make_pair(0,1));
    edges.push_back(make_pair(1,2));

    int n=5;
    //adjacency list
    unordered_map<int, list<int> > adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }

    vector<int> dsc(n,-1);   //discovery time
    vector<int> low(n,-1);   //lowest discovery time
    unordered_map<int, bool> visited;
    vector<int> ap(n,0);     //articulate point

    int timer;

    //dfs
    for(int i=0; i<n; i++){
        if(!visited[i]){
            dfs(i, -1, timer, dsc, low, visited, ap, adj);
        }
    }
    //then print
}