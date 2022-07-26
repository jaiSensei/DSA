#include<unordered_map>
#include<queue>
#include<list>
#include<set>

void adjlist(unordered_map<int, list<int> > &adj, vector<pair<int, int>> &edges){
    
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}
void bsf(unordered_map<int, list<int> > adj, unordered_map<int, bool> &visited, vector<int> &ans, int node){
    
    queue<int> q;
    //putiing the first value
    q.push(node);
    visited[node] = 1;
    
    while(!q.empty()){
        int frontnode = q.front();
        q.pop();
        
        ans.push_back(frontnode);
        
        for(auto i:adj[frontnode]){     //till end of neighbour elements exist
            
            //if not visited
            if(!visited[i]){
                q.push(i);
                visited[i] = 1;
            }
        }
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int, list<int> > adj;
    vector<int> ans;
    unordered_map<int, bool> visited;
    
    //creating a adjenceny list
    adjlist(adj, edges);
    
    //for loop only because disconnected graph is present
    for(int i=0; i<vertex; i++){
        if(!visited[i]){
            bsf(adj,visited, ans, i);      //disconnected graph else only this part will be required
        }
    }
    return ans;
}