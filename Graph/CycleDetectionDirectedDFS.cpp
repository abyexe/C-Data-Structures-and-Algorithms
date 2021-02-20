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

bool dfsRec(vector<int> graph[] , int src , bool visited[] , bool recSt[]){
    visited[src] = true;
    recSt[src] = true;

    for(auto x : graph[src]){
        if(!visited[x] && dfsRec(graph , x, visited, recSt)){
            return true;
        } else if(recSt[x] == true){
                return true;
            }
    }
    recSt[src] = false;
    return false;
}

bool dfs(vector<int> graph[] , int V){
    bool visited[V];

    bool recSt[V];

    for(int i= 0 ; i<V;i++){
        visited[i] = false;
        recSt[i] = false;
    }

    for(int i=0; i<V;i++){
        if(!visited[i]){
            if(dfsRec(graph , i , visited , recSt)){
                return true;
            }
        }
    }
    
    return false;
}

int main(){
    int V = 6 ;

    bool result;

    vector<int> graph[V];

    addEdge(graph , 0 , 1, false);
    addEdge(graph , 2 , 1, false);
    addEdge(graph , 2 , 3, false);
    addEdge(graph , 3 , 4, false);
    addEdge(graph , 4 , 5, false);
    //addEdge(graph , 5 , 3, false);

    cout<<"Graph : \n";
    printGraph(graph , V);

    result = dfs(graph , V);

    if(result){
        cout<<"\n Graph is Cyclic  \n\n";
    } else {
        cout<<"\n Graph is Acyclic  \n\n";
    }

    return 0;
}