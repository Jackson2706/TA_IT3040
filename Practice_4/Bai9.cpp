#include <iostream>
#include <queue>
#include <climits>

std::vector<int> dijkstra(const std::vector< std::vector<std::pair<int, int>>> &adj){
    std::priority_queue<std::pair<int, int>> Q;
    std::vector<int> d(adj.size(), INT_MAX);
    d[0] = 0;
    Q.push({0, 0});
    while(!Q.empty()){
        int du = -Q.top().first;
        int u = Q.top().second;
        Q.pop();
        if(du != d[u]) continue;
        for(auto e:adj[u]){
            int v = e.first;
            int c = e.second;
            if(d[v] > d[u] + c){
                d[v] = d[u] + c;
                Q.push({-d[v], v});
            }
        }
    }
    return d;
}

int main(){
    int n = 9;
    std::vector<std::vector<std::pair<int,int> > > adj(n);
    auto add_edge = [&adj](int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    };
    add_edge(0, 1, 4);
    add_edge(0, 7, 8);
    add_edge(1, 7, 11);
    add_edge(1, 2, 8);
    add_edge(2, 3, 7);
    add_edge(2, 8, 2);
    add_edge(3, 4, 9);
    add_edge(3, 5, 14);
    add_edge(4, 5, 10);
    add_edge(5, 6, 2);
    add_edge(6, 7, 1);
    add_edge(6, 8, 6);
    add_edge(7, 8, 7);
    
    std::vector<int> d = dijkstra(adj);
    for(int i = 0; i < d.size();i++){
        std::cout <<"Distance "<< 0 << "->" << i <<" = " << d[i] << std::endl;
    }
    return 0;
}