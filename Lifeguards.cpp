#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("lifeguards.in", "r", stdin);
    freopen("lifeguards.out", "w", stdout);
	long long n;
    cin >> n;
    pair<long long, long long> inout[2*n] =  {};
    long long times_alone[n+1] = {};
    for (long long i = 1; i < n+1; i++) {
        cin >> inout[2*i-2].first;
        cin >> inout[2*i-1].first;
        inout[2*i-2].second = i;
        inout[2*i-1].second = -i;
    }
    sort(inout, inout+2*n);
    long long current = 0;
    set<long long> duty = {};
    long long last = 0, now = 0;
    long long min_alone = 10000000000;
    for (long long i = 0; i < 2*n; i++) {
        now = inout[i].first;
        if (duty.size() == 1) {
            times_alone[*duty.begin()] += now-last;
        }
        if (duty.size() > 0) {
            current += now-last;
        }
        if (inout[i].second > 0) {
            current++;
            duty.insert(inout[i].second);
        }
        else {
            current--;
            duty.erase(-inout[i].second);
            min_alone = min(min_alone, times_alone[-inout[i].second]);
        }
        last = now;
    }
    cout << current - min_alone;
}
