#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, d;
    cin >> n >> d;
    long long a[n] = {};
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    long long left = 0;
    long long ans = 1;
    for (long long right = 0; right < n; right++) {
        while (a[right]-a[left] > d) {
            left++;
        }
        ans *= (right-left+1);
        ans %= 1000000009;
    }
    cout << ans << "\n";
}
