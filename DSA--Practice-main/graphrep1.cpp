/*
code for undirected, unweighted
*/


#include <iostream>
using namespace std;

class Graph{
public:
    int adjMatrix[100][100];
    int vertices;

    Graph(int v){
        vertices = v;
        for(int i = 0; i < vertices; i++){
            for(int j = 0; j < vertices; j++){
                adjMatrix[i][j]= 0;
            }
        }
    }

    void addedge(int x, int y){
        if(x >= vertices || y >= vertices || x < 0 || y < 0){
            cout<<"ivalid vertices"<<endl;
            return;
        }
        adjMatrix[x][y] = 1;
        adjMatrix[y][x] = 1;
    }

    void removedge(int x, int y){
        if(x >= vertices || y <= vertices || x < 0 || y < 0){
            cout<<"invalid vertices"<<endl;
            return;
        }
        adjMatrix[x][y] = 0;
        adjMatrix[y][x] = 0;
    }

    void display(){
        cout<<"Adjacency matrix is:"<<endl;
        for(int i = 0; i < vertices ; i++){
            for (int j = 0; j < vertices; j++){
                cout<<adjMatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    int nvertices, edges, x, y;
    cout<<"enter the num of vertices: ";
    cin>>nvertices;

    Graph g(nvertices);

    cout<<"enter the num of edges: ";
    cin>>edges;

    for(int i = 0; i < edges; i++){
        cout<<"enter edge (u,v):";
        cin>> x >> y;
        g.addedge(x, y);
    }

    g.display();


}