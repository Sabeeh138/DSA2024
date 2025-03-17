#include <iostream>
#include <vector>
using namespace std;

// Function to add a directed edge from vertex i to vertex j
void addEdge(vector<vector<int>>& adj, int i, int j) {
    adj[i].push_back(j); // Only add the edge from i to j (directed)
}

// Function to display the adjacency list
void displayAdjList(const vector<vector<int>>& adj) {
    for (int i = 0; i < adj.size(); i++) {
        cout << i << ": "; // Print the vertex
        for (int j : adj[i]) {
            cout << j << " "; // Print its adjacent vertices
        }
        cout << endl;
    }
}

// Main function
int main() {
    // Create a graph with 4 vertices and no edges
    int V = 4;
    vector<vector<int>> adj(V);

    // Now add edges one by one
    addEdge(adj, 0, 1); // Directed edge from 0 to 1
    addEdge(adj, 0, 2); // Directed edge from 0 to 2
    addEdge(adj, 1, 2); // Directed edge from 1 to 2
    addEdge(adj, 2, 3); // Directed edge from 2 to 3

    cout << "Adjacency List Representation:" << endl;
    displayAdjList(adj);

    return 0;
}
