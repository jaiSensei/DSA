#include<bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    //adjaceny list
    unordered_map<int, list<pair<int, int>>> adj;
    for(int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    vector<int> key(n+1, INT_MAX);
    vector<bool> mst(n+1, false);
    vector<int> parent(n+1, -1);
    
    //first element
    key[1] = 0;
    parent[1] = -1;
    
    //algo
    for(int i=1; i<n; i++) {
        int mini = INT_MAX;
        int u; //stores index of smallest element ,, index is only the element 

        //finding smallest element
        for(int v=1; v<=n; v++) {
            if(!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v]; // one that has minimum wieght
            } 
        }
        mst[u] = true; // mark that true

        //check neighbours
        for(auto i : adj[u]) {
            int v = i.first;   //node 
            int w = i.second;   //weight of edge

            //finding the smallest weight element and that is not visited ie true
            if(!mst[v] && w < key[v]) {
                key[v] = w;    
                parent[v] = u;    //updating parent of that element
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> answer;
    
    //not starting from 0 because 0 is not mapped started from 1 as stated in question check output
    //not starting 1 because 1 has -1 as parent tree wrong ho jaeyga

    for(int i=2; i<=n; i++) {
        answer.push_back({{parent[i], i}, key[i]});        //***important way to push data in a pair of pair
    }
    
    return answer;
    
}