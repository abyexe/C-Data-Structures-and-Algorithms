#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> graph[] , int src , int dest ){
    graph[src].push_back(dest);
}

void printGraph(vector<int> graph[] , int V){
    for(int i = 0; i<V; i++){
        cout<<i<<" ---> ";
        for(auto x : graph[i]){
            cout<<x<<" ";
        }
        cout<<endl;
    }
}

void dfs(vector<int> graph[] , int src , bool visited[] , stack<int> &st){
    visited[src] = true;

    for(auto x : graph[src]){
        if(!visited[x]){
            dfs(graph , x, visited , st);
        }
    }

    st.push(src);
}

void topologicalSort(vector<int> graph[] , int V){
    stack<int> st;

    bool visited[V];

    for(int i =0 ; i< V ; i++){
        visited[i] = false;
    }

    for(int i = 0 ; i < V ; i++){
        if(!visited[i]){
            dfs(graph , i ,  visited  , st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    
}

int main(){
    int V = 5;

    vector<int> graph[V];

    // addEdge(graph , 0 , 2 );
    // addEdge(graph , 0 , 3 );
    // addEdge(graph , 1 , 3 );
    // addEdge(graph , 1 , 4 );
    // addEdge(graph , 2 , 3 );

    addEdge(graph,0, 1); 
    addEdge(graph,1, 3); 
    addEdge(graph,2, 3); 
    addEdge(graph,3, 4); 
    addEdge(graph,2, 4); 
    
    cout<<"\nGraph : \n";
    printGraph(graph , V);


    // cout<<"\nIndegree Array : ";
    // for(int i=0;i<V;i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<"\n";

    cout<<"\nTopological Sort : ";
    topologicalSort(graph , V);
    cout<<"\n\n";

    return 0;
}