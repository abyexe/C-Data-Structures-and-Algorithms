#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest , int indegree[]){
    graph[src].push_back(dest);
    indegree[dest]++;
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

bool bfs(vector<int> graph[] , int indegree[] , int V){
    int vertex , count=0;
   
    queue<int> q;

    for(int i=0 ; i<V ; i++){
        if(indegree[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){
        vertex = q.front();
        q.pop();
        
        for(auto x : graph[vertex]){
            indegree[x] -= 1;
            if(indegree[x] == 0){
                q.push(x);
            }
        }

        count++;
    }
    return (count != V);
}

int main(){
    int V = 6 ;

    bool result;

    vector<int> graph[V];

    int indegree[V];

    for(int i=0;i<V;i++){
        indegree[i] = 0;
    }

    addEdge(graph , 0 , 1, indegree);
    addEdge(graph , 2 , 1, indegree);
    addEdge(graph , 2 , 3, indegree);
    addEdge(graph , 3 , 4, indegree);
    addEdge(graph , 4 , 5, indegree);
    // addEdge(graph , 5 , 3, indegree);

    cout<<"Graph : \n";
    printGraph(graph , V);

    result = bfs(graph , indegree , V);

    if(result){
        cout<<"\nGraph is Cyclic  \n\n";
    } else {
        cout<<"\nGraph is Acyclic  \n\n";
    }

    return 0;
}