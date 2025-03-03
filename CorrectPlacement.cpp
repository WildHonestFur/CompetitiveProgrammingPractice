#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;


int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, i;
        cin >> n;
        pair<pair<long long, long long>, long long> rect[n] = {};
        for (i = 0; i < n; i++) {
            long long h, w;
            cin >> h >> w;
            rect[i] = {{max(h, w), min(h, w)}, i};
        }
        sort(rect, rect+n);
        long long stack[n] = {};
        long long mapping[n] = {};
        long long inverse[n] = {};
        for (i = 0; i < n; i++) {
            stack[i] = -1;
            mapping[i] = rect[i].second;
            inverse[rect[i].second] = i;
        }
        long long k = n-1, j = n-2;
        while (k > 0 and j >= 0) {
            if (rect[k].first.first > rect[j].first.first) {
                stack[k] = j;
                k -= 1;
            }
            else {
                j -= 1;
            }
        }
        pair<long long, long long> pre[n] = {};
        pre[0] = {rect[0].first.second, mapping[0]};
        for (i = 1; i < n; i++) {
            if (rect[i].first.second < pre[i-1].first) {
                pre[i] = {rect[i].first.second, mapping[i]};
            }
            else {
                pre[i] = pre[i-1];
            }
        }
        for (j = 0; j < n; j++) {
            i = inverse[j];
            if (stack[i] == -1) {
                cout << -1 << " ";
            }
            else {
                if (rect[i].first.second > pre[stack[i]].first) {
                    cout << pre[stack[i]].second+1 << " ";
                }
                else {
                    cout << -1 << " ";
                }
            }
        }
        cout << "\n";
    }

}
