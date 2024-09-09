#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;

void bfs(int start, const vector<vector<int>>& adj) {
    map<int, bool> visited; // Using map to keep track of visited nodes
    queue<int> q;
    vector<int> ans;
    
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        ans.push_back(current);  // Add the node to the result

        for (int neighbor : adj[current]) {
            // Check if the neighbor has not been visited
            if (!visited[neighbor]) {
                visited[neighbor] = true; // Mark it as visited
                q.push(neighbor);
            }
        }
    }

    for (int i : ans) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int V, e;
    cout << "Enter the number of vertices (V):" << endl;
    cin >> V;
    cout << "Enter the number of edges (E):" << endl;
    cin >> e;
    
    vector<vector<int>> adj(V);
    int u, v;

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter the starting node for BFS:" << endl;
    cin >> start;
    
    bfs(start, adj);
}
