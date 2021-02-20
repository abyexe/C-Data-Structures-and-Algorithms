#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , bool bidirec){
    graph[src].push_back(dest);

    if(bidirec){
        graph[dest].push_back(src);
    }
}

void printGraph(vector<int> graph[] , int V){
    for(int i=0 ; i<V ; i++){
        
        cout<<i<<" ---> ";

        for(auto x : graph[i]){
            cout<<x<<" ";
        }

        cout<<"\n";
    }
}

void shortestPath(vector<int> graph[] , int src , int V ){
    int dist[V] , vertex;

    for(int i=0;i<V;i++){
        dist[V] = -1;
    }

    dist[0] = 0;

    vector<bool> visited(V , false);

    queue<int> q;

    q.push(src);

    visited[src] = true;

    while(!q.empty()){
        vertex = q.front();

        q.pop();

        for(auto x : graph[vertex]){
            if(!visited[x]){
                dist[x] = dist[vertex] + 1;
                visited[x] = true;
                q.push(x);
            }
        }
    }

    cout<<"Distance of each vertex from src : ";
    for(int i=0 ; i<V ; i++){
        cout<<dist[i]<<" ";
    }
}

int main(){

    int V = 4 ;

    vector<int> graph[V];

    addEdge(graph , 0, 2,  true);
    addEdge(graph , 0, 1, true);
    addEdge(graph , 1, 2, true);
    addEdge(graph , 1, 3, true);
    addEdge(graph , 2, 3, true);

    cout<<"Graph : \n";
    printGraph(graph , V);

    shortestPath(graph , 0 , V);

    return 0;
}