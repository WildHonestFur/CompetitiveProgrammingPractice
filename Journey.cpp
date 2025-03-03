#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, a, b, c;
        cin >> n >> a >> b >> c;
        long long three = a+b+c;
        long long ans = n/three;
        ans *= 3;
        long long remain = n % three;
        long long count = 0;
        while (remain > 0) {
            if (count == 0) {
                remain -= a;
            }
            else if (count == 1) {
                remain -= b;
            }
            else {
                remain -= c;
            }
            count++;
        }
        cout << ans+count << "\n";
    }
}