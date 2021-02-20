#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest  , bool bidirec){
    graph[src].push_back(dest);

    if(bidirec){
        graph[dest].push_back(src);
    }
}

void printGraph(vector<int> graph[] , int V){
    for(int i=0;i<V;i++){

        cout<<i<<" ---> ";

        for(int x : graph[i]){
            cout<<x<<" ";
        }

        cout<<"\n";
    }
}

void dfs(vector<int> graph[] , int src , bool visited[]){
    visited[src] = true;

    cout<<src<<" ";

    for(auto x : graph[src]){
        if(!visited[x]){
            dfs(graph , x , visited);
        }
    }
}

int main(){
    int V = 5;

    vector<int> graph[V];

    bool visited[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    addEdge(graph , 0, 1, true);
    addEdge(graph , 0, 2,true);
    addEdge(graph , 1, 3, true);
    addEdge(graph , 1, 4,true);
    addEdge(graph , 2, 3,true);
    addEdge(graph , 3, 4,true);

    printGraph(graph , V);

    cout<<"DFS Traversal : ";
    dfs(graph , 0 , visited);

    return 0;
}