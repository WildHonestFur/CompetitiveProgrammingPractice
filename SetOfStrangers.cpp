#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, m;
        cin >> n >> m;
        long long ans = 0;
        long long colors[n*m+1] = {};
        bool two = false;
        long long a[n][m] = {};
        for (long long j = 0; j < n; j++) {
            for (long long k = 0; k < m; k++) {
                cin >> a[j][k];
                if (colors[a[j][k]] == 0) {
                    colors[a[j][k]] = 1;
                }
                if (k > 0) {
                    if (a[j][k] == a[j][k-1]) {
                        two = true;
                        colors[a[j][k]] = 2;
                    }
                }
                if (j > 0) {
                    if (a[j][k] == a[j-1][k]) {
                        two = true;
                        colors[a[j][k]] = 2;
                    }
                }
            }
        }
        for (long long j = 0; j < n*m; j++) {
            ans += colors[j+1];
        }
        if (two) {
            ans -= 2;
        }
        else {
            ans -= 1;
        }
        cout << ans << "\n";
    }
}
