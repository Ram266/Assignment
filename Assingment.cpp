// Assignment solution for c++ 

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int, int> pii;
const int INF = INT_MAX;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int,int>>> adj(n+1);

    for(auto& edge : times) {
        int u = edge[0], v = edge[1], w = edge[2];
        adj[u].push_back({v, w});
    }

    vector<int> dist(n+1, INF);
    dist[k] = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, k});

    while(!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if(d > dist[u]) continue;

        for(auto& v : adj[u]) {
            if(dist[v.first] > dist[u] + v.second) {
                dist[v.first] = dist[u] + v.second;
                pq.push({dist[v.first], v.first});
            }
        }
    }

    int maxDelay = 0;
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF) return -1;
        maxDelay = max(maxDelay, dist[i]);
    }
    return maxDelay;
}

int main() {
    int n, m, k;
    cout << "Enter the number of nodes and edges: ";
    cin >> n >> m;
    cout << "Enter the edges and their weights: \n";
    vector<vector<int>> times(m);
    for(int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        times[i] = {u, v, w};
    }
    cout << "Enter the source node: ";
    cin >> k;

    int delay = networkDelayTime(times, n, k);
    if(delay == -1) {
        cout << "Not all nodes can receive the signal\n";
    } else {
        cout << "Minimum time taken for all nodes to receive the signal: " << delay << endl;
    }
    return 0;
}


/* Input: Enter the number of nodes and edges: 4 3
 Enter the edges and their weights: 
 2 1 1
 2 3 1
 3 4 1
Enter the source node: 2
Output:
Minimum time taken for all nodes to receive the signal: 2
*/
