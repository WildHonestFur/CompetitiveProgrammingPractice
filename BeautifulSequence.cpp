#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

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

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long ans = 0;
        long long a[n] = {};
        long long onecount = 0;
        long long twocount = 0;
        long long score = 0;
        long long pairs = 0;
        for (long long j = 0; j < n; j++) {
            cin >> a[j];
            if (a[j] == 1) {
                if (onecount > 0) {
                    score *= mod_power(2, twocount, 998244353);
                }
                score += 1;
                onecount += 1;
                score %= 998244353;
                twocount = 0;
            }
            if (a[j] == 2) {
                twocount += 1;
            }
            if (a[j] == 3) {
                ans += (score*mod_power(2, twocount, 998244353))%998244353;
                pairs += onecount;
                pairs %= 998244353;
            }
            
        }
        long long finalans = (ans-pairs)%998244353;
        if (finalans < 0) {
            finalans += 998244353;
        } 
        cout << finalans << "\n";
    }
}
