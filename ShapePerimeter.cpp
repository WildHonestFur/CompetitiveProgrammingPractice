#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, m;
        cin >> n >> m;
        long long ans = 0;
        pair<long long, long long> now = {};
        for (long long q = 0; q < n; q++) {
            cin >> now.first >> now.second;
            if (q > 0) {
                ans += 2*now.first+2*now.second;
            }
            else {
                ans += 4*m;
            }
        }
        cout << ans << "\n";
    }
}
