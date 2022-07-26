#include<unordered_map>
#include<queue>
#include<list>
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    
    //create adj
    unordered_map<int, list<int>> adj;
    for(int i=0; i<e; i++){
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    //storing indegree
    vector<int> indegree(v);
    for(auto i: adj){
        for(auto j: i.second){
            indegree[j]++;
        }
    }
    
    //storing all 0 indegree nodes
    queue<int> q;
    for(int i=0; i<v; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }
    
    //bfs
    vector<int> ans;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        
        for(auto neighbour : adj[front]){
            
            //reduce indegree of the neighbour node
            indegree[neighbour]--;
            //if it becomes 0 push into queue
            if(indegree[neighbour] == 0){
                q.push(neighbour);
            }
        }
 
    }
    return ans;
}