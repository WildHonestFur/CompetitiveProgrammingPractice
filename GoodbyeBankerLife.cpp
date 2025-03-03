#include <bits/stdc++.h>
using namespace std;

bool isodd(long long n, long long r) {
    return (n & r) == r;
}

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k;
        cin >> n >> k;
        for (long long i = 0; i < n; i++) {
            if (isodd(n-1, i)) {
                cout << k << " ";
            }
            else {
                cout << 0 << " ";
            }
        }
        cout << "\n";
    }
}
