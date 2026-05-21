#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>

#include <climits>
using namespace std;

int prims(int V, unordered_map<string, vector<pair<string, int>>>& graph, string src){
    
    unordered_map<string, bool> visited;
    unordered_map<string, int> dist;
    
    for(auto &it : graph){
        dist[it.first] = INT_MAX;
    }

    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    int totalCost = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        string node = it.second;
        int cost = it.first;
        
        if(visited[node]) continue;
        
        visited[node] = true;
        totalCost += cost;
        
        for(auto ngh : graph[node]){
            string adj = ngh.first;
            int weight = ngh.second;
            
            if(!visited[adj] && weight < dist[adj]){
                dist[adj] = weight;
                pq.push({weight, adj});
            }
        }
    }
    
    return totalCost;
}

int main(){
    int V, E;
    cin >> V >> E;
    
    unordered_map<string, vector<pair<string, int>>> graph;
    
    for(int i = 0; i < E; i++){
        string u, v;
        int w;
        cin >> u >> v >> w;
        
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    
    string source;
    cin >> source;
    
    cout << "Min cost : " << prims(V, graph, source);
}