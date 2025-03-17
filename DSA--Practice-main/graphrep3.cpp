/*
undirected weighted
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
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addedge(int x, int y, int w){
        if(x >= vertices || y >= vertices || x < 0 || y < 0){
            cout<<"Invalid vertice"<<endl;
            return;
        }
        adjMatrix[x][y] = w;
        adjMatrix[y][x] = w;
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
#include <iostream>
using namespace std;

class Graph {
public:
    int adjMatrix[100][100];
    int vertices;

    Graph(int v) {
        vertices = v;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                adjMatrix[i][j] = 0;
            }
        }
    }

    void addedge(int x, int y, int w) {
        if (x >= vertices || y >= vertices || x < 0 || y < 0) {
            cout << "Invalid vertice" << endl;
            return;
        }
        adjMatrix[x][y] = w;
        adjMatrix[y][x] = w;
    }

    void removedge(int x, int y) {
        if (x >= vertices || y >= vertices || x < 0 || y < 0) {
            cout << "invalid vertices" << endl;
            return;
        }
        adjMatrix[x][y] = 0;
        adjMatrix[y][x] = 0;
    }

    void display() {
        cout << "Adjacency matrix is:" << endl;
        for (int i = 0; i < vertices; i++) {
            for (int j = 0; j < vertices; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int vertices = 5;
    Graph g(vertices);

    g.addedge(0, 1, 10);
    g.addedge(0, 4, 20);
    g.addedge(1, 2, 30);
    g.addedge(1, 3, 40);
    g.addedge(3, 4, 50);

    g.display();

    g.removedge(1, 3);

    cout << "After removing an edge:" << endl;
    g.display();

    return 0;
}

