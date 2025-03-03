#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	long long n;
    long long ans = 0;
    cin >> n;
    pair<long long, long long> peaks[n] = {};
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        peaks[i] = {y, x};
    }
    sort(peaks, peaks+n);
    long long prey[n] = {};
    long long prex[n] = {};
    for (long long i = 0; i < n-1; i++) {
        prey[i] = peaks[n-1].first-peaks[i].first;
        prex[i] = peaks[n-1].second-peaks[i].second;
    }
    //long long higher[n] = {};
    for (long long i = 0; i < n; i++) {
        long long y = peaks[i].first, x = peaks[i].second;
        bool hidden = false;
        for (long long j = i+1; j < n; j++) {
            long long ydif = prey[i]-prey[j];
            long long xdif = prex[i]-prex[j];
            if (xdif < 0) {
                xdif *= -1;
            }
            if (xdif <= ydif) {
                hidden = true;
                break;
            }
        }
        if (!hidden) {
            ans += 1;
        }
    }

    cout << ans << "\n";
}
