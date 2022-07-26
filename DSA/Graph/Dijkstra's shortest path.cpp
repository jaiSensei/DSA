#include<unordered_map>
#include<list>
#include<set>
#include<limits.h>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    
    //making adjacency list
    unordered_map<int, list<pair<int,int>> > adj;
    
    for(int i=0; i<edges; i++){
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> distance(vertices);
    for(int i=0; i<vertices; i++){
        distance[i] = INT_MAX;
    }
    
    //set for storing and getting front node
    set<pair<int,int> > st;
    
    //setting source distance to itself 0
    distance[source] = 0;
    st.insert(make_pair(0, source));    //inserting pair 0 distance to source
    
    while(!st.empty()){
        auto front = *(st.begin());    //** important
        
        int nodedistance = front.first;
        int topnode = front.second;
        
        st.erase(st.begin());     //eeleting front node
        
        //getting all the neighbour nodes of the frontnode
        for(auto neighbour : adj[topnode]){

            //if new path has less weight then 
            if(nodedistance + neighbour.second < distance[neighbour.first]){   //.second in this accesses the weight dont get confused
                
                //checking if stack doesnt have same index with different weight in stack that is not yet popped
                auto record = st.find(make_pair(distance[neighbour.first], neighbour.first));
                
                //removing the data if found
                if(record != st.end()){
                    st.erase(record);
                }
                
                //replace data in ans vector
                distance[neighbour.first] = nodedistance + neighbour.second;
                //insert that in stack
                st.insert(make_pair(distance[neighbour.first], neighbour.first));
            }
        }
    }
    //return ans vector
    return distance;
   
}
