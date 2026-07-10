#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, u, v;
    cin >> n >> m >> u >> v;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> parent(n + 1, 0);
    vector<bool> visited(n + 1, false);
    vector<int> iter(n + 1, 0);

    vector<int> stack;
    stack.push_back(u);
    visited[u] = true;
    parent[u] = -1;

    bool found = false;

    if (u == v) {
        found = true;
    }

    while (!stack.empty() && !found) {
        int cur = stack.back();

        if (iter[cur] < (int)g[cur].size()) {
            int next = g[cur][iter[cur]];
            iter[cur]++;

            if (!visited[next]) {
                visited[next] = true;
                parent[next] = cur;
                stack.push_back(next);

                if (next == v) {
                    found = true;
                }
            }
        }
        else {
            stack.pop_back();
        }
    }

    if (!found) {
        cout << -1 << '\n';
    }
    else {
        vector<int> path;
        int cur = v;
        while (cur != -1) {
            path.push_back(cur);
            cur = parent[cur];
        }

        for (int i = (int)path.size() - 1; i >= 0; i--) {
            cout << path[i];
            if (i > 0) cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}