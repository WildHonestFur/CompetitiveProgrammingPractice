#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long a[n] = {};
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long best = 0;
        pair<long long, long long> bestpair = {1, 1};
        for (long long left = 0; left < n; left++) {
            long long count = 0;
            for (long long right = left; right < n; right++) {
                if (a[right] < a[left]) {
                    count++;
                }
                else if (a[right] > a[left]) {
                    count--;
                }
                if (count > best) {
                    best = count;
                    bestpair = {left+1, right+1};
                }
            }
        }
        cout << bestpair.first << " " << bestpair.second << "\n";
    }
}
