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

bool bfs(vector<int> graph[] , int src ,bool visited[] , int parent){
    visited[src] = true;

    int vertex;

    queue<int> q;

    q.push(src);

    while(!q.empty()){
        vertex = q.front();
        
        q.pop();

        for(auto x : graph[vertex]){
            if(!visited[x]){
                visited[x] = true;
                q.push(x);
            } else {
                if(parent != x){
                    return true;
                }
            }
        }

        parent = vertex;
    }

    return false;
}

bool bfsCycleDetection(vector<int> graph[] , int V){
    bool visited[V];

    for(int i=0;i<V;i++){
        visited[i] = false;
    }

    for(int i=0 ; i<V ; i++){
        if(!visited[i]){
            if(bfs(graph , i , visited , -1)){
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    int V = 9 ;

    bool result;

    vector<int> graph[V];

    //Cyclic example V = 4
    // addEdge(graph , 0, 2,  true);
    // addEdge(graph , 0, 1, true);
    // addEdge(graph , 1, 2, true);
    // addEdge(graph , 1, 3, true);
    // addEdge(graph , 2, 3, true);


    //Acyclic example V = 5
    // addEdge(graph , 0 , 1 , true);
    // addEdge(graph , 0 , 2 , true);
    // addEdge(graph , 1 , 3 , true);
    // addEdge(graph , 1 , 4 , true);

    //Cyclic example 4 components V= 9
    addEdge(graph , 0, 1, true);
    addEdge(graph , 0, 2, true);
    addEdge(graph , 0, 3, true);
    addEdge(graph , 1, 3, true);
    addEdge(graph , 2, 3, true);
    addEdge(graph , 4, 5, true);
    addEdge(graph , 4, 6, true);

    //Acyclic example with 3 components V = 5
    // addEdge(graph , 0, 1, true);
    // addEdge(graph , 1, 2, true);
    

    cout<<"Graph : \n";
    printGraph(graph , V);

    result = bfsCycleDetection(graph , V);

    if(result){
        cout<<"\n Graph is Cyclic \n\n";
    } else {
        cout<<"\n Graph is Acyclic \n\n";
    }

    return 0;
}