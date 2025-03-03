#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, m, k;
        cin >> n >> m >> k;
        if (k < n-1) {
            for (long long j = 0; j < m+k; j++) {
                long long test;
                cin >> test;
                if (j < m) {
                    cout << 0;
                }
            }
            cout << "\n";
        }
        else if (k == n) {
            for (long long j = 0; j < m+k; j++) {
                long long test;
                cin >> test;
                if (j < m) {
                    cout << 1;
                }
            }
            cout << "\n";
        }
        else {
            long long a[m] = {};
            long long q[n+1] = {};
            for (long long j = 0; j < m; j++) {
                cin >> a[j];
            }
            for (long long j = 0; j < k; j++) {
                long long val;
                cin >> val;
                q[val] = 1;
            }
            for (long long j = 0; j < m; j++) {
                if (q[a[j]] == 1) {
                    cout << 0;
                }
                else {
                    cout << 1;
                }
            }
            cout << "\n";
        }
    }
}
