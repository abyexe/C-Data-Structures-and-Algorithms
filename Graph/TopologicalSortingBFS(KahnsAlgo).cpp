#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , int indegree[]){
    graph[src].push_back(dest);
    indegree[dest] += 1;
}

void printGraph(vector<int> graph[] , int V){
    for(int i =0; i<V;i++){
        cout<<i<<" ---> ";

        for(auto x : graph[i]){
            cout<<x<<" ";
        }

        cout<<"\n";
    }
}

void topologicalSort(vector<int> graph[] , int indegree[] , int V){
    int vertex;
   
    queue<int> q;

    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        vertex = q.front();
        q.pop();
        cout<<vertex<<" ";
        
        for(auto x : graph[vertex]){
            indegree[x] -= 1;
            if(indegree[x] == 0){
                q.push(x);
            }
        }
    }

}

int main(){
    int V = 5;

    vector<int> graph[V];

    int indegree[V];

    for(int i =0; i < V; i++){
        indegree[i] = 0;
    }

    addEdge(graph , 0 , 2 , indegree);
    addEdge(graph , 0 , 3 , indegree);
    addEdge(graph , 1 , 3 , indegree);
    addEdge(graph , 1 , 4 , indegree);
    addEdge(graph , 2 , 3 , indegree);
    
    cout<<"\nGraph : \n";
    printGraph(graph , V);


    // cout<<"\nIndegree Array : ";
    // for(int i=0;i<V;i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<"\n";

    cout<<"\nTopological Sort : ";
    topologicalSort(graph , indegree , V);
    cout<<"\n\n";

    return 0;
}