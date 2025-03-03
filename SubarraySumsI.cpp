#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x;
    cin >> n >> x;
    long long a[n] = {};
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long ans = 0;
    long long left = 0, right = 0;
    long long sum = a[0];
    while (left < n and right < n) {
        if (sum > x) {
            left++;
            sum -= a[left-1];
        }
        else if (sum < x) {
            right++;
            sum += a[right];
        }
        else {
            left++;
            sum -= a[left-1];
            ans++;
        }
    }
    cout << ans << "\n";
}
