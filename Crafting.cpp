#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long a[n] = {};
        for (long long j = 0; j < n; j++) {
            cin >> a[j];
        }
        long long minpos = 10000000000;
        long long negative = 0;
        long long value = 0;
        for (long long j = 0; j < n; j++) {
            long long val;
            cin >> val;
            if (val <= a[j]) {
                minpos = min(minpos, a[j]-val);
            }
            else {
                negative++;
                value = val-a[j];
            }
        }
        if (negative <= 1) {
            if (negative == 0) {
                cout << "Yes" << "\n";
            }
            else if (value <= minpos) {
                cout << "Yes" << "\n";
            }
            else {
                cout << "No" << "\n";
            }
        }
        else {
            cout << "No" << "\n";
        }
    }
}
