#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        string s;
        cin >> s;
        bool sub = false;
        long long ans = 0;

        for (long long i = 0; i < n; i++) {
            if (s[i] == '1') {
                sub = true;
            }
            else if (sub) {
                sub = false;
                ans += 2;
            }
        }
        if (sub) {
            ans += 1;
        }
        cout << ans << "\n";
    }
}
