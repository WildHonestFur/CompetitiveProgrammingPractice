#include <bits/stdc++.h>
using namespace std;

long long permute() {
    long long m, n;
    cin >> n >> m;
    long long ans[m*n] = {};
    bool yes = true;
    for (long long i = 0; i < n; i++) {
        long long first;
        cin >> first;
        long long minval = first;
        for (long long j = 0; j < m-1; j++) {
            long long next;
            cin >> next;
            if (abs(first-next)%n != 0) {
                yes = false;
            }
            minval = min(minval, next);        
        }
        ans[minval] = i+1;
    }
    if (!yes) {
        return -1;
    }
    for (long long i = 0; i<n; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}


int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long x = permute();
        if (x == -1) {
            cout << -1 << "\n";
        }
    }
}
