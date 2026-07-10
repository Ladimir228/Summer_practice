#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    long long answer = 0;
    int left = 0;

    for (int right = 0; right < n; right++) {
        while (a[right] - a[left] > k) {
            left++;
        }
        long long w = right - left + 1;
        long long cntBefore = w - 1;
        if (cntBefore >= 2) {
            answer += cntBefore * (cntBefore - 1) / 2;
        }
    }

    cout << answer << "\n";

    return 0;
}