#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , bool bidirec){
    graph[src].push_back(dest);

    if(bidirec){
        graph[dest].push_back(src);
    }
}

void printGraph(vector<int> graph[] , int V){
    
    for(int i=0;i<V ; i++){
        for(auto x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    } 

}

void bfs(vector<int> graph[] , int src , int V ){
    int vertex;
    
    vector<bool> visited(V,false);

    queue<int> q;

    visited[src] = true;

    q.push(src);
    
    while(!q.empty()){
        vertex = q.front();
        
        q.pop();

        cout<<vertex<<" ";

        for(auto x : graph[vertex]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
                
        }
    }

}

int main(){
    int V = 5;

    vector<int> graph[5];

    addEdge(graph , 0, 1, true);
    addEdge(graph , 0, 4, true);
    addEdge(graph , 1, 2, true);
    addEdge(graph , 1, 4, true);
    addEdge(graph , 2, 3, true);

    printGraph(graph , V);

    cout<<"BFS traversal : ";
    bfs(graph , 0 , V);


    return 0;
}
