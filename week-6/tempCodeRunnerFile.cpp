#include<iostream>
#include<vector>
using namespace std;
bool dfs(int node,int dest,vector<int>visited,vector<vector<int>>adj){
    if(node==dest){
        return true;
    }
    visited[node]=true;
    for(int n:adj[node]){
        if(!visited[n]){
            if(dfs(n,dest,visited,adj)){
                return true;
            }
        }
    }
    return false;
}
int main(){
    int V;
    cin>>V;
    vector<vector<int>>adj(V);
    int edge;
    cin>>edge;
    for(int i=0;i<edge;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int>visited(V,false);
    int src,dest;
    cin>>src>>dest;
    if(dfs(src,dest,visited,adj)){
        cout<<"Path exist";
    }
    else{
        cout<<"path does not exist";
    }
    return 0;
}