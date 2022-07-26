#include<unordered_map>
#include<queue>
#include<list>
#include<set>


//set is used when sorted answer is required as in set every thing is sorted


void adjlist(unordered_map<int, set<int> > &adj, vector<pair<int, int>> &edges){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
}
void bsf(unordered_map<int, set<int> > adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        
        ans.push_back(frontnode);
        
        for(auto i:adj[frontnode]){
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, set<int> > adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    adjlist(adj, edges);
    
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bsf(adj,visited, ans, i);
        }
    }
    return ans;
}