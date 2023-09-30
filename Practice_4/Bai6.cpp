#include <vector>
#include <list>
#include <iostream>
#include <queue>
using namespace std;

void bfs(std::vector<std::list<int> > adj){
    std::queue<int> Q;
    std::vector<bool> was(adj.size());
    Q.push(1);
    was[1] = true;
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        std::cout << u << std::endl;
        for(int v: adj[u]){
            if(!was[v]){
                Q.push(v);
                was[v] = true;
            }
        }
    }
    std::cout <<std::endl;
}

int main(){
        int n = 7;
    std::vector<std::list<int> > adj;
    adj.resize(n+1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    bfs(adj);
    return 0;
}