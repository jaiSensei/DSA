#include<algorithm>

//comparator for arranging edges on basis of weight
bool cmp(vector<int> &a, vector<int> &b){
    return a[2] < b[2];    //a pehle element and b second uske niche wala
}

//intiallizing parent with itself pointer and rank as 0
void makeset(vector<int> &parent, vector<int> &rank, int n){
    for(int i=0; i<n; i++){
        parent[i] = i;
        rank[i] = 0;
    }
}
int findparent(vector<int> &parent, int node){
    if(parent[node] == node){     //if parent of node is itself then return ans
        return node;
    }
    return parent[node] = findparent(parent, parent[node]);      //directly attaching it to source for path compression
}

void unionset(int u, int v, vector<int> &parent, vector<int> &rank){
    u = findparent(parent, u);
    v = findparent(parent, v);
    
    if(rank[u] < rank[v]){
        parent[u] = v;
    }
    else if(rank[v] < rank[u]){
        parent[v] = u;
    }
    else{
        parent[v] = u;
        rank[u]++;
    }
}
int minimumSpanningTree(vector<vector<int>>& edges, int n)
{
    //sorting edges
    sort(edges.begin(), edges.end(), cmp);
      vector<int> rank(n);
      vector<int> parent(n);
      makeset(parent, rank, n);
    
    int minweight = 0;
    
    for(int i=0; i<edges.size(); i++){
        int u = findparent(parent, edges[i][0]);
        int v = findparent(parent, edges[i][1]);
        int wt = edges[i][2];
        
        //nodes are of different components
        if(u != v){
            minweight+=wt;
            unionset(u,v,parent,rank);
        }
    }
    return minweight;

}