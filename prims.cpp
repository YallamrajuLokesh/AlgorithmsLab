#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> pi;

void prims(int V, int E, vector<vector<int>> adj[]) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    vector<bool> vis(V, false);
    int sum = 0;
    pq.push({0, 0});

    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        int wt = it.first;
        int node = it.second;

        if (vis[node]) // Corrected the access operator to []
            continue;

        vis[node] = true; // Corrected the access operator to []
        sum += wt;

        for (auto it : adj[node]) {
            int adjnode = it[0];
            int weight = it[1]; // Renamed the variable to avoid conflict
            if (!vis[adjnode]) {
                pq.push({weight, adjnode}); // Corrected the usage of curly braces to parentheses
            }
        }
    }

    cout << "The sum of the weights of the Minimum Spanning Tree is: " << sum << endl;
}



int main(){
  int V, E;
  cout << "Enter the number of vertices: ";
  cin >> V;
  cout << "Enter the number of edges: ";
  cin >> E;
  cout << "Enter the edges (format: u v w, where u and v are nodes and w is the weight):" << endl;
  vector<vector<int>>adj[V];
  for (int i = 0; i < E; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      adj[u].push_back({v, w});
      adj[v].push_back({u, w});
  }
      prims(V, E, adj);

      return 0;
  }
