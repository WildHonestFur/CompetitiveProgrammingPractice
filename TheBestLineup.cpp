#include <bits/stdc++.h>
using namespace std;

bool comp(pair<long long, long long> a, pair<long long, long long> b) {
    if (a.first == b.first) {
        return a.second < b.second;
    }
    return a.first > b.first;
}

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        pair<long long, long long> a[n] = {};
        for (long long j = 0; j < n; j++) {
            cin >> a[j].first;
            a[j].second = j;
        }
        sort(a, a+n, comp);
        cout << a[0].first << " ";
        pair<long long, long long> last = a[0];
        int strikes = 0;
        for (long long j = 1; j < n; j++) {
            if (a[j].second <= last.second) {
                strikes++;
            }
            if (strikes == 2) {
                break;
            }
            last = a[j];
            cout << a[j].first << " ";
        }
        cout << "\n";
    }
}