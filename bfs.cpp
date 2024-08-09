#include<iostream>
#include<queue>
#include<list>
#include<map>
using namespace std;

void bfs(int start, vector<int> adj[]) {
    map<int, bool> visited;
    queue<int> q;
    vector<int> ans;
    
    visited[start] = true;
    q.push(start);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        ans.push_back(current);  // Add the node to the result

        for (auto it : adj[current]) {
            if (!visited[it]) {
                visited[it] = true;
                q.push(it);
            }
        }
    }

    for (auto i : ans) {
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
    
    vector<int> adj[V];
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
