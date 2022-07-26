#include<bits/stdc++.h>
using namespace std;
class Graph{
    public:
    unordered_map<int,list<pair<int,int> > > adj;

    void addEdge(int u,int v, int weight){
        pair<int,int> p = make_pair(v, weight);
        adj[u].push_back(p);
    }
    void dfstopo( vector<int> &visited , stack<int> &s, int node){
    visited[node] = 1;
    
    for(auto neighbour : adj[node]){
        if(!visited[neighbour.first]){
            dfstopo(visited, s, neighbour.first);
        }
    }
    s.push(node);
    }

    void getshortestpath(int src, vector<int> &dist, stack<int> &topo){
        dist[src] = 0;

        while(!topo.empty()){
            int top = topo.empty();
            topo.pop();

            if(top != INT_MAX){
                for(auto i: adj[top]){
                    if(dist[top] + i.second < dist[i.first]){
                        i.first = i.second + dist[top];
                    }
                }
            }
        }
    }
    
}

};
int main(){

    Graph G;
    G.addEdge(1, 3, 6);

    G.addEdge(1, 2, 2);

    G.addEdge(0, 1, 5);

    G.addEdge(0, 2, 3);

    G.addEdge(3, 4, -1);

    G.addEdge(2, 4, 4);

    G.addEdge(2, 5, 2);

    G.addEdge(2, 3, 7);

    G.addEdge(4, 5, -2);


    //topological sort
    int n =6;
    vector<int> visited(6);
    stack<int> s;
    
    for(int i=0; i<6; i++){
        if(!visited[i]){
            G.dfstopo(visited, s, i);
            
        }
    }

    int src=1;
    vector<int> distance(6);

    for(int i=0; i<n; i++)
        distance[i] = INT_MAX;

    //getshortestpath
    G.getshortestpath(src, distance, s);

    //print answer
    return 0;

}