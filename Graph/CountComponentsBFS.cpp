#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , bool bidirec){
    graph[src].push_back(dest);
    
    if(bidirec){
        graph[dest].push_back(src);
    }
}

void printGraph(vector<int> graph[] , int V){
    for(int i=0;i<V;i++){
        cout<<i<<" ---> ";
        for(auto x : graph[i]){
            cout<<x<<" ";
        }
        cout<<"\n";
    }
}

void bfs(vector<int> graph[] , int src , int V , bool visited[]){

    int vertex;

    visited[src] = true;

    queue<int> q;

    q.push(src);

    while(!q.empty()){
        vertex = q.front();

        //cout<<vertex<<" ";

        q.pop();

        for(auto x : graph[vertex]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            }
        }
    }
}

int bfsDisconnected(vector<int> graph[] , int V){
    int count = 0;

    bool visited[V];

    for(int i=0;i<V;i++)
        visited[i] = false;

    for(int i=0;i<V;i++){
        if(!visited[i]){
            bfs(graph , i , V , visited);
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

    //cout<<"BFS traversal : ";
    cout<<"Number of componenets : "<<bfsDisconnected(graph , V);

    return 0;
}