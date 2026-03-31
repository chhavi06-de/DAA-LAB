#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int bipartite(int V,vector<vector<int>>adj){
    vector<int>c(V,-1);
    queue<int>q;
    for(int i=0;i<V;i++){
        if(c[i]==-1){
            c[i]=0;
            q.push(i);
            while(!q.empty()){
                int node=q.front();
                q.pop();
                for(int j:adj[node]){
                    if(c[j]==-1){
                        c[j]=1-c[node];
                        q.push(j);
                    }
                    else{
                        if(c[j]==c[node]){
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
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
    if(bipartite(V,adj)){
        cout<<"yes graph is bipartite";
    }
    else{
        cout<<"no graph is not bipartite";
    }
}