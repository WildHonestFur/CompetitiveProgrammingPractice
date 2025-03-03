#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long mod_power(long long base, long long exponent, long long mod) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result = (result*base) % mod;
        }
        base = base*base % mod;
        exponent /= 2;
    }
    return result;
}

long long value(long long n) {
    long long ans;
    if (n % 2 == 0) {
        ans = mod_power(2, n-1, 1000000007)-mod_power(2, n/2, 1000000007);
    }
    else {
        ans = mod_power(2, n-1, 1000000007)-mod_power(2, (n-1)/2, 1000000007);
    }
    return ans;
}

int main() {
	long long t, computed;
    cin >> t;
    long long pre[100001] =  {};
    computed = 0;

    for (long long k = 0; k < t; k++) {
        long long l, r, i;
        cin >> l >> r;
        if (r > computed) {
            for (i = computed+1; i < r+1; i++) {
                pre[i] = pre[i-1]+value(i);
            }
            computed = r;
        }
        long long answer = (pre[r]-pre[l-1]) % 1000000007;
        if (answer < 0) {
            answer += 1000000007;
        }
        cout << answer << "\n";
    }
}
