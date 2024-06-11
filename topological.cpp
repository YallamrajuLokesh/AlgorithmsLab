#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

void toputil(int Node, vector<int> adj[], map<int, bool>& visited, stack<int>& s) {
    visited[Node] = true;
    for (auto i : adj[Node]) {
        if (!visited[i]) {
            toputil(i, adj, visited, s);
        }
    }
    s.push(Node);
}

void topo(int V, vector<int> adj[]) {
    map<int, bool> visited;
    stack<int> s;
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            toputil(i, adj, visited, s);
        }
    }

    cout << "Topological Sort: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}

int main() {
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V];  // Create an adjacency list

    cout << "Enter the edges (u v) one by one:\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);  // Directed edge from u to v
    }

    topo(V, adj);  // Perform Topological Sort

    return 0;
}
