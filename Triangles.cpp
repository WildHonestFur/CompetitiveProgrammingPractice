#include <bits/stdc++.h>
using namespace std;


int main() {
    freopen("triangles.in", "r", stdin);
    freopen("triangles.out", "w", stdout);
	long long n;
    long long mod = 1000000007;
    cin >> n;
    vector<pair<long long, long long>> ysame[20001] = {};
    vector<pair<long long, long long>> xsame[20001] = {};
    long long sums[n] = {};
    for (long long i = 0; i < n; i++) {
        long long x, y;
        cin >> x >> y;
        x += 10000;
        y += 10000;
        ysame[y].push_back({x, i});
        xsame[x].push_back({y, i});
        sums[i] = 1;
    }

    for (long long i = 0; i < 20001; i++) {
        long long ysize = ysame[i].size();
        if (ysize) {
            sort(ysame[i].begin(), ysame[i].end());
            long long s = 0;
            for (long long j = 0; j < ysize; j++) {
                s += ysame[i][j].first-ysame[i][0].first;
            }
            sums[ysame[i][0].second] *= s;
            sums[ysame[i][0].second] %= mod;
            for (long long j = 1; j < ysize; j++) {
                s += (2*j-ysize)*(ysame[i][j].first-ysame[i][j-1].first);
                sums[ysame[i][j].second] *= s;
                sums[ysame[i][j].second] %= mod;
            }
        }
    }

    long long ans = 0;

    for (long long i = 0; i < 20001; i++) {
        long long xsize = xsame[i].size();
        if (xsize) {
            sort(xsame[i].begin(), xsame[i].end());
            long long s = 0;
            for (long long j = 0; j < xsize; j++) {
                s += xsame[i][j].first-xsame[i][0].first;
            }
            sums[xsame[i][0].second] *= s;
            sums[xsame[i][0].second] %= mod;
            ans += sums[xsame[i][0].second];
            for (long long j = 1; j < xsize; j++) {
                s += (2*j-xsize)*(xsame[i][j].first-xsame[i][j-1].first);
                sums[xsame[i][j].second] *= s;
                sums[xsame[i][j].second] %= mod;
                ans += sums[xsame[i][j].second];
                ans %= mod;
            }
        }
    }

    cout << ans << "\n";
}
