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

void dfsRec(vector<int> graph[] , int src , bool visited[]){
    visited[src] = true;

    //cout<<src<<" ";

    for(auto x : graph[src]){
        if(!visited[x]){
            dfsRec(graph , x , visited);
        }
    }
}

int dfs(vector<int> graph[] , int V){
    int count = 0;

    bool visited[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
    }
    //cout<<"DFS Traversal : ";
    for(int i=0;i<V ; i++){
        if(!visited[i]){
            dfsRec(graph , i , visited);
            count++;
        }
    }

    return count;
}

int main(){
    int V = 9;

    vector<int> graph[V];
    
    addEdge(graph , 0, 1, true);
    addEdge(graph , 0, 2, true);
    addEdge(graph , 0, 3, true);
    addEdge(graph , 1, 3, true);
    addEdge(graph , 2, 3, true);
    addEdge(graph , 4, 5, true);
    addEdge(graph , 4, 6, true);

    printGraph(graph , V);

    cout<<"Number of components : "<<dfs(graph , V);

    return 0;
}