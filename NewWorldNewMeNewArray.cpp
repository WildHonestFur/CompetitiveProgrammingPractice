#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k, p;
        cin >> n >> k >> p;
        k = abs(k);
        if (n*p < k) {
            cout << -1 << "\n";
        }
        else {
            long long ans = (k+p-1) / p;
            cout << ans << "\n";
        }
    }
}
