#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m;
    cin >> n >> m;
    long long genres[m+1] = {};
    for (long long i = 0; i < n; i++) {
        long long val;
        cin >> val;
        genres[val]++;
    }
    long long ans = n*n;
    for (long long i = 1; i < m+1; i++) {
        ans -= genres[i]*genres[i];
    }
    cout << ans/2 << "\n";
}
