#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , bool bidirec){
    graph[src].push_back(dest);

    if(bidirec){
        graph[dest].push_back(src);
    }
}

void printGraph(vector<int> graph[]){
    for(int i=0;i<4;i++){
        for(int x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

void dfs(vector<int> graph[] , int src , vector<int> visited){
    cout<<src<<" ";

    visited[src] = 1;

    for(int i=0 ; i < graph[src].size() ; i++){
        if(visited[graph[src][i]] == 0){
            
            dfs(graph , graph[src][i] , visited);
        }
    }
}

int main(){
    vector<int> graph[4];

    vector<int> visited(4,0);

    // for(int i = 0 ; i<5 ;i++){
    //     visited[i] = 0;
    // }

    addEdge(graph , 0 , 1 , true);
    addEdge(graph , 0 , 2 , true);
    addEdge(graph , 1 , 2 , true);
    addEdge(graph , 1 , 3 , true);
    
    printGraph(graph);

    //cout<<graph[0][1];

    cout<<"DFS -> ";
    dfs(graph , 0 , visited);

    return 0;
}