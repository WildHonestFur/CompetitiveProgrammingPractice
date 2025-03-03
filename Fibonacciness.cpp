#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long a[4] = {};
        for (int j = 0; j < 4; j++) {
            cin >> a[j];
        }
        long long val1 = a[0]+a[1];
        long long val2 = a[3]-a[2];
        long long val3 = a[2]-a[1];
        int ans = 1;
        if (val1 != val2) {
            ans += 1;
            if (val3 != val2 and val3 != val1) {
                ans += 1;
            }
        }
        else {
            if (val2 != val3) {
                ans += 1;
            }
        }
        cout << 4-ans << "\n";
    }
}
