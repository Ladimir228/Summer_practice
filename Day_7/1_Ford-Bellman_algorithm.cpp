#include <iostream>
#include <vector>
#include <queue>
#include <sstream>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, s;
    cin >> n >> m >> s;

    vector<int> U(m), V(m);
    vector<long long> W(m);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;
        U[i] = u; V[i] = v; W[i] = w;
        adj[u].push_back(v);
    }

    const long long INF = LLONG_MAX / 2;
    vector<long long> dist(n + 1, INF);
    dist[s] = 0;

    for (int iter = 0; iter < n - 1; iter++) {
        bool changed = false;
        for (int i = 0; i < m; i++) {
            if (dist[U[i]] != INF && dist[U[i]] + W[i] < dist[V[i]]) {
                dist[V[i]] = dist[U[i]] + W[i];
                changed = true;
            }
        }
        if (!changed) break;
    }

    vector<bool> affected(n + 1, false);
    queue<int> q;
    for (int i = 0; i < m; i++) {
        if (dist[U[i]] != INF && dist[U[i]] + W[i] < dist[V[i]]) {
            if (!affected[V[i]]) {
                affected[V[i]] = true;
                q.push(V[i]);
            }
        }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (!affected[v]) {
                affected[v] = true;
                q.push(v);
            }
        }
    }

    bool hasNegCycle = false;
    for (int i = 1; i <= n; i++) {
        if (affected[i]) { hasNegCycle = true; break; }
    }

    if (hasNegCycle) {
        cout << "Negative cycle\n";
    }
    else {
        ostringstream out;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INF) out << "inf";
            else out << dist[i];
            if (i < n) out << ' ';
        }
        out << "\n";
        cout << out.str();
    }

    return 0;
}