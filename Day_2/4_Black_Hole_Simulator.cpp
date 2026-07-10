#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long M;
    cin >> N >> M;

    vector<pair<long long, int>> a(N);
    for (int i = 0; i < N; ++i) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }

    sort(a.begin(), a.end());

    long long cur = M;
    vector<int> order;

    bool f = true;
    for (int i = 0; i < N; ++i) {
        if (a[i].first < cur) {
            cur += a[i].first;
            order.push_back(a[i].second);
        }
        else {
            f = false;
            break;
        }
    }

    if (!f) {
        cout << "NO\n";
    }
    else {
        cout << "YES\n";
        for (int idx : order) {
            cout << idx << ' ';
        }
        cout << '\n';
    }

    return 0;
}