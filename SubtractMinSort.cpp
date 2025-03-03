#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long a[n] = {};
        string ans = "YES";
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (long long i = 0; i < n-1; i++) {
            long long m = min(a[i], a[i+1]);
            a[i] -= m;
            a[i+1] -= m;
        }
        for (long long i = 0; i < n-1; i++) {
            if (a[i+1] < a[i]) {
                ans = "NO";
                break;
            }
        }
        cout << ans << "\n";
    }
}