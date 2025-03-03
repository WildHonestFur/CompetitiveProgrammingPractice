#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, x;
    cin >> n >> x;
    pair<long long, long long> a[n] = {};
    for (long long i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i+1;
    }
    sort(a, a+n);
    for (long long i = 0; i < n-2; i++) {
        long long left = i+1, right = n-1;
        long long sum = a[i].first+a[left].first+a[right].first;
        while (left < right) {
            if (sum > x) {
                sum -= a[right].first;
                right--;
                sum += a[right].first;
            }
            else if (sum < x) {
                sum -= a[left].first;
                left++;
                sum += a[left].first;
            }
            else {
                cout << a[i].second << " " << a[left].second << " " << a[right].second << "\n";
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << "\n";
}
