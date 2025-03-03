#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k;
        cin >> n >> k;
        vector<pair<long long, long long>> groups = {};
        vector<pair<long long, long long>> a = {};
        int blues = 0;
        long long start = 0;
        char current = 'R';
        for (long long i = 0; i < n; i++) {
            char x;
            cin >> x;
            if (x == 'B' and !blues) {
                blues = 1;
                current = 'B';
            }
            if (blues) {
                if (current != x) {
                    groups.push_back({start, i-1});
                    start = i;
                    current = x;
                }
            }
        }
        if (current == 'B') {
            groups.push_back({start, n-1});
        }

        long long blue = (groups.size()+1)/2;
        long long currentg = 0;
        long long m = 0;
        bool started = false;

        for (long long i = 0; i < n; i++) {
            long long ai;
            cin >> ai;
            if (currentg < groups.size()) {
                if (groups[currentg].first == i) {
                    started = true;
                    m = max(m, ai);
                }
                if (groups[currentg].second == i) {
                    started = false;
                    currentg++;
                    m = max(m, ai);
                    a.push_back({m, currentg});
                    m = 0;
                }
                if (started) {
                    m = max(m, ai);
                }
            }
        }

        if (k >= blue) {
            cout << 0 << "\n";
        }
        else {
            blue -= k;
            /*vector<long long> pre_maxes = {};
            deque<long long> b, r;
            for (long long i = 0; i < 2; i++) {
                pre_maxes.push_back(a[i].first);
            }
            b.push_back(a[0].second);
            a.push_back(a[1].second);
            for (long long i = 2; i < a.size(); i++) {
                //pre_maxes.push_back(max(pre_maxes[i-2], a[i].first));
                if (i % 2 == 0) {
                    if (!b.empty() and a.front() < (long long) (i-1)/2 - blue + 1) {
                        b.pop_front();
                    }
                    while (!b.empty() and a[b.back()].first <= a[i].first) {
                        b.pop_back();
                    }
                    b.push_back(a[i].second);

                    pre_maxes.push_back(a[b.front()].first);
                }
                else {
                    if (!r.empty() and a.front() < (long long) (i-1)/2 - blue + 1) {
                        r.pop_front();
                    }
                    while (!r.empty() and a[r.back()].first <= a[i].first) {
                        r.pop_back();
                    }
                    r.push_back(a[i].second);

                    pre_maxes.push_back(a[r.front()].first);
                }
            }
            for (long long i = 0; i < a.size(); i++) {
                cout << pre_maxes[i] << " ";
            }
            cout << "\n";*/
            set<long long> used = {};
            sort(a.begin(), a.end());
            long long index = 0;
            long long count = 0;
            long long max = 0;
            while (count < blue) {
                if (used.count(a[index].second) == 0) {
                    count++;
                    max = a[index].first;
                    used.insert(a[index].second+1);
                    used.insert(a[index].second-1);
                }
                index++;
            }
            cout << max << "\n";
        }
    }
}
