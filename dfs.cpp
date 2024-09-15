#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Utility function for DFS traversal
void dfsUtil(int Node, vector<vector<int>>& adj, map<int, bool>& visited, vector<int>& ls) {
    visited[Node] = true;  // Mark the current node as visited
    ls.push_back(Node);    // Add the node to the result list
    for (int it : adj[Node]) {
        if (!visited[it]) {
            dfsUtil(it, adj, visited, ls);  // Recur for unvisited neighbors
        }
    }
}

// Function to perform DFS traversal
void dfs(int V, vector<vector<int>>& adj) {
    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    map<int, bool> visited;  // Map to store visited status for each node
    vector<int> ls;          // Vector to store the DFS traversal result

    dfsUtil(start, adj, visited, ls);  // Start DFS from the given starting node

    // Print the DFS traversal result
    cout << "DFS Traversal starting from vertex " << start << ": ";
    for (int i : ls) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<int>> adj(V);  // Create an adjacency list

    cout << "Enter the edges (u v) one by one:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // Assuming the graph is undirected
    }

    dfs(V, adj);  // Perform DFS starting from the given vertex

    return 0;
}
