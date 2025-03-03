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
        sort(a, a+n);
        long long pair = 0;
        long long skip = 0;
        for (long long i = 0; i < n-1; i++) {
            if (a[n-1-i] == a[n-2-i]) {
                pair = a[n-1-i];
                skip = n-2-i;
                break;
            }
        }
        if (pair == 0) {
            cout << -1 << '\n';
        }
        else {
            bool ans = false;
            for (long long i = 0; i < skip-1; i++) {
                if (a[i+1] - a[i] < 2*pair) {
                    cout << pair << " " << pair << " " << a[i] << " " << a[i+1] << "\n";
                    ans = true;
                    break;
                }
            }
            if (!ans) {
                for (long long i = skip+2; i < n-1; i++) {
                    if (a[i+1] - a[i] < 2*pair) {
                        cout << pair << " " << pair << " " << a[i] << " " << a[i+1] << "\n";
                        ans = true;
                        break;
                    }
                }
                if (n-1 > skip+1 and skip > 0 and !ans) {
                    if (a[skip+2] - a[skip-1] < 2*pair) {
                        cout << pair << " " << pair << " " << a[skip-1] << " " << a[skip+2] << "\n";
                        ans = true;
                    }
                }
            }
            if (!ans) {
                cout << -1 << "\n";
            }
        }
    }
}
