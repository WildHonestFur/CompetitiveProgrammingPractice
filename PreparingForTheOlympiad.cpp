#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n; 
        cin >> n;
        long long a[n] = {};
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long ans = a[n-1];
        for (long long i = 0; i < n; i++) {
            long long b;
            cin >> b;
            if (i > 0) {
                if (b < a[i-1]) {
                    ans += a[i-1]-b;
                }
            }
        }
        cout << ans << "\n";
    }
}