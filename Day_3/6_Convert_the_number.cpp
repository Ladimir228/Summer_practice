#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> dp(n + 1);
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        long long best = dp[i - 1] + i;
        if (i % 2 == 0) {
            best = min(best, dp[i / 2] + i);
        }
        if (i % 3 == 0) {
            best = min(best, dp[i / 3] + i);
        }
        dp[i] = best;
    }

    cout << dp[n] << '\n';

    return 0;
}