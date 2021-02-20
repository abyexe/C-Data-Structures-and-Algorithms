#include<bits/stdc++.h>
using namespace std;

class Graph{
    public:
        int v;
        list<int> *adj;
            
        Graph(int n){
            this->v = n;
            this->adj = new list<int>(n); 
        }

        void addEdge(int src , int dest , bool bidirec=true){
            cout<<"inside addEdge\n";
            adj[src].push_back(dest);

            if(bidirec){
                adj[dest].push_back(src);
            }
        }

        void dfsHelper(int src , unordered_map<int , bool> visited){
            visited[src] = true;

            cout<<src<<" "<<endl;
            
            for(auto neighbour : this->adj[src]){
                if(not visited[neighbour]){
                    dfsHelper(neighbour , visited);
                }
            }
        }   

        void dfs(int src){
            unordered_map<int , bool> visited;
            dfsHelper(src , visited);
        }       

        int connectedComponent(){
            cout<<"inside connectedComponent\n";
            unordered_map<int , bool> visited;
            int result = 0;

            for(int i=0 ; i< v-1 ; i++){
                if(!visited[i]){
                    result++;
                    dfsHelper(i , visited);
                }
            }

            return result;
        }
};

int main(){
    cout<<"Hello\n";

    Graph g(6);

    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,5);
    g.connectedComponent();

    return 0;
}
