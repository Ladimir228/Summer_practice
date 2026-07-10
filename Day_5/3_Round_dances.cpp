#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    ll fact = 1;
    for (ll i = 2; i <= n - 1; ++i) {
        fact = (fact * i) % MOD;
    }
    ll inv = (MOD + 1) / 2;
    ll res = (fact * inv) % MOD;

    cout << res;
}