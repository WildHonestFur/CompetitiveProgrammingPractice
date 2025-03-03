#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long m, a, b, c;
        cin >> m >> a >> b >> c;
        long long ans = 0;
        ans += min(a, m);
        ans += min(b, m);
        ans += min(c, 2*m-ans);
        cout << ans << "\n";
    }
}
