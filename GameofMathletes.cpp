#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k;
        cin >> n >> k;
        vector<long long> negative = {};
        vector<long long> positive = {};
        long long equals = 0, negs = 0, pos = 0;
        for (long long i = 0; i < n; i++) {
            long long val;
            cin >> val;
            if (2*val > k) {
                positive.push_back(val);
                pos++;
            }
            else if (2*val < k) {
                negative.push_back(val);
                negs++;
            }
            else {
                equals++;
            }
        }
        long long ans = equals/2;
        sort(negative.begin(), negative.end());
        sort(positive.begin(), positive.end());
        long long pi = 0, ni = negs-1;
        while (true) {
            if (ni < 0 or pi > pos-1) {
                break;
            }
            if (positive[pi]+negative[ni] == k) {
                ans++;
                pi++;
                ni--;
            }
            else if (positive[pi]+negative[ni] > k) {
                ni--;
            }
            else {
                pi++;
            }
        }
        cout << ans << "\n";
    }
}