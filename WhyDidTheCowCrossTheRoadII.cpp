#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("maxcross.in", "r", stdin);
	freopen("maxcross.out", "w", stdout);
	long n, b, k, i;
    cin >> n >> k >> b;
    int lights[n+1] = {};
    long pre[n+1] = {};

    for (i = 1; i < b+1; i++) {
        long broken;
        cin >> broken;
        lights[broken] = 1;
    }

    for (i = 1; i < n+1; i++) {
        pre[i] = pre[i-1]+lights[i];
    }

    long ans = 100001;
    for (i = 0; i < n-k+1; i++) {
        ans = min(ans, pre[i+k]-pre[i]);
    }

    cout << ans;
}
