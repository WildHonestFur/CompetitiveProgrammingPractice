#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

long long area(vector<pair<long long, long long>> a, long long n) {
	sort(a.begin(), a.end());
    long long premax[n] = {};
    premax[0] = a[0].second;
    long long premin[n] = {};
    premin[0] = a[0].second;
    for (long long i = 1; i < n; i++) {
        premax[i] = max(premax[i-1], a[i].second);
        premin[i] = min(premin[i-1], a[i].second);
    }
    long long full = (premax[n-1]-premin[n-1])*(a[n-1].first-a[0].first);
    long long best = 0;
    long long maxfar = a[n-1].second, minfar = a[n-1].second;
    for (long long i = n-2; i >= 0; i--) {
        maxfar = max(maxfar, a[i+1].second);
        minfar = min(minfar, a[i+1].second);
        if (a[i+1].first != a[i].first or premax[i] < minfar or premin[i] > maxfar) {
            long long left = (premax[i]-premin[i])*(a[i].first-a[0].first);
            long long right = (maxfar-minfar)*(a[n-1].first-a[i+1].first);
            best = max(best, full-left-right);
        }
    }
    return best;
}

int main() {
    freopen("split.in", "r", stdin);
	freopen("split.out", "w", stdout);
	long long n;
	cin >> n;
	vector<pair<long long, long long>> a(n);
	for (long long i = 0; i < n; i++) {
		cin >> a[i].first;
		cin >> a[i].second;
	}
    long long a1 = area(a, n);
    for (long long i = 0; i < n; i++) {
		swap(a[i].first, a[i].second);
	}
    long long a2 = area(a, n);
    cout << max(a1, a2) << "\n";
}
