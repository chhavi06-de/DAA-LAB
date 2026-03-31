#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack){
    
    visited[node] = true;
    recStack[node] = true;

    for(int neigh : adj[node]){
        
        if(!visited[neigh]){
            if(dfs(neigh, adj, visited, recStack))
                return true;
        }

        else if(recStack[neigh]){
            return true;
        }
    }

    recStack[node] = false;
    return false;
}

bool detectCycle(int V, vector<vector<int>>& adj){

    vector<bool> visited(V,false);
    vector<bool> recStack(V,false);

    for(int i=0;i<V;i++){
        if(!visited[i]){
            if(dfs(i,adj,visited,recStack))
                return true;
        }
    }

    return false;
}

int main(){

    int V;
    cin>>V;

    vector<vector<int>> adj(V);

    int edges;
    cin>>edges;

    for(int i=0;i<edges;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v); // directed edge
    }

    if(detectCycle(V,adj)){
        cout<<"Yes Cycle Exists";
    }
    else{
        cout<<"No Cycle Exists";
    }
}