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

bool dfsRec(vector<int> graph[] , int src , bool visited[] , int parent){
    visited[src] = true;

    for(auto x : graph[src]){
        if(!visited[x]){
            if(dfsRec(graph , x , visited , src)){
                return true;
            }
        } else {
            if(parent != x){
                return true;
            }
        }
    }
    return false;
}

bool dfs(vector<int> graph[] , int V){
    bool visited[V];

    for(int i=0 ; i<V ; i++){
        visited[i] = false;
    }

    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            if(dfsRec(graph , i , visited , -1)){
                return true;
            }
        }
    }

    return false;
}

int main(){

    int V = 5 ;

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
    // addEdge(graph , 0, 1, true);
    // addEdge(graph , 0, 2, true);
    // addEdge(graph , 0, 3, true);
    // addEdge(graph , 1, 3, true);
    // addEdge(graph , 2, 3, true);
    // addEdge(graph , 4, 5, true);
    // addEdge(graph , 4, 6, true);

    //Acyclic example with 3 components V = 5
    addEdge(graph , 0, 1, true);
    addEdge(graph , 1, 2, true);
    

    cout<<"Graph : \n";
    printGraph(graph , V);

    result = dfs(graph , V);

    if(result){
        cout<<"\nGraph is Cyclic\n\n";
    } else {
        cout<<"\nGraph is Acyclic\n\n";
    }

    return 0;
}