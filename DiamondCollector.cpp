#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    freopen("diamond.in", "r", stdin);
	freopen("diamond.out", "w", stdout);
	long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    
    long long forwards[n] = {};
    long long left = 0;
    long long best = 0;
    for (long long right = 0; right < n; right++) {
        while (a[right]-a[left] > k) {
            left++;
        }
        best = max(best, right-left+1);
        forwards[right] = best;
    }

    reverse(a.begin(), a.end());
    long long backwards[n] = {};
    left = 0;
    best = 0;
    for (long long right = 0; right < n; right++) {
        while (a[left]-a[right] > k) {
            left++;
        }
        best = max(best, right-left+1);
        backwards[right] = best;
    }

    best = 0;
    for (long long i = 0; i < n-1; i++) {
        best = max(forwards[i]+backwards[n-2-i], best);
    }
    cout << best << "\n";
}
