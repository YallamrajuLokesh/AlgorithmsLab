#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pi;

vector<int> dij(int v, int s, vector<vector<int>> adj[]) 
{ 
    vector<int> dist(v, INT_MAX); 
    dist[s] = 0;

    priority_queue<pi, vector<pi>, greater<pi>> pq; 
    pq.push({0, s});

    while (!pq.empty()) 
    { 
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node]) 
        { 
            int adjnode = it[0];
            int adjtime = it[1];

            if (dis + adjtime < dist[adjnode]) 
            { 
                dist[adjnode] = dis + adjtime; 
                pq.push({dist[adjnode], adjnode}); 
            } 
        } 
    } 
    return dist; 
}

int main() 
{ 
    vector<string> city = {"SF", "LA", "DNV", "DAL", "CHI", "BOS", "NY"};
    int v = city.size();

    cout << "City Indexes:" << endl;
    for (int i = 0; i < v; i++) 
    {
        cout << i << " -> " << city[i] << endl;
    }
    cout << endl;

    cout << "Enter the number of routes (edges):" << endl;
    int e;
    cin >> e;

    vector<vector<int>> adj[v];
    cout << "Enter routes in the format (SOURCE, DESTINATION, TIME):" << endl;
    for (int i = 0; i < e; i++) 
    {
        int u, v, time;
        cin >> u >> v >> time;
        adj[u].push_back({v, time});
        adj[v].push_back({u, time}); // If the graph is undirected
    }

    int source = 0; // Assuming "SF" (San Francisco) as the source city

    vector<int> res = dij(v, source, adj); 

    for (int i = 1; i < res.size(); i++) 
        cout << "Shortest time from SF to " << city[i] << " is = " << res[i] << " units" << endl << endl;

    return 0; 
}
