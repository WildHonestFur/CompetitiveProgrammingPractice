#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k;
        cin >> n >> k;
        set<long long> good = {};
        long long a[k] = {};
        vector<long long> values[k] = {};
        for (long long i = 0; i < n; i++) {
            long long x;
            cin >> x;
            long long val = x % k;
            a[val]++;
            values[val].push_back(i+1);
            if (a[val] == 1) {
                good.insert(val);
            }
            else if (a[val] == 2) {
                good.erase(val);
            }
        }
        if (good.size() == 0) {
            cout << "No" << "\n";
        }
        else {
            cout << "Yes" << "\n" << values[*good.begin()][0] << "\n";
        }
    }
}