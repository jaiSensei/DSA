#include<unordered_map>
#include<list>
#include<queue>
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  //create adj
unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++){
        int u = edges[i].first - 1;   //nodes were starting with 1 best if subtracted else errors come
        int v = edges[i].second - 1;
        
        adj[u].push_back(v);
    }
    
    //storing indegree
    vector<int> indegree(n);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    
    //storing all 0 indegree nodes
    queue<int> q;
    for(int i=0; i<n; i++){    //not from one because subtracted one earlier
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    //bfs
    //vector<int> ans;
    int count=0;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        count++;
        
        for(auto neighbour : adj[front]){
            indegree[neighbour]--;
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
 
    }
    if(count == n){
        return false;
    }
    else {
        return true;
    }
    
}