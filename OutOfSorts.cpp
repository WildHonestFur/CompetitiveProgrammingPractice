#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    freopen("sort.in", "r", stdin);
	freopen("sort.out", "w", stdout);
	long long n;
    cin >> n;
    pair<long long, long long> a[n] = {};
    long long back = 0;
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a, a+n);
    for (long long i = 0; i < n; i++) {
        back = max(back, a[i].second-i);
    }

    
    cout << back+1 << "\n";
}
