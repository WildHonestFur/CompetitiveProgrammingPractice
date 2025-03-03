#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, m;
        cin >> n >> m;
        long long count = 0;
        long long ans = 0;
        long long sizes[n] = {};
        for (long long i = 0; i < n; i++) {
            string s;
            cin >> s;
            count += s.size();
            if (count <= m) {
                ans++;
            }
        }
        cout << ans << "\n";
    }
}
