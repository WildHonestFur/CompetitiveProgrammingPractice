#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, k;
    cin >> n >> k;
    long long friends[n] = {};
    for (long long i = 0; i < n; i++) {
        long long val;
        cin >> val;
        friends[val-1] = i;
    }
    for (long long i = 0; i < n; i++) {
        long long cyclelength = 0;
        long long first[n] = {};
        vector<long long> cycle = {};
        long long current = i;
        long long time = 1;
        while (true) {
            if (first[current] != 0) {
                cyclelength = time-first[current];
                break;
            }
            first[current] = time;
            time++;
            cycle.push_back(current);
            current = friends[current];
        }
        long long ans = k % cyclelength;
        cout << cycle[ans]+1 << " ";
    }
}
