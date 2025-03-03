#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n;
    cin >> n;
    string s;
    cin >> s;
    long long q;
    cin >> q;
    while (q--) {
        long long m;
        char c;
        cin >> m >> c;
        long long left = 0;
        long long amount = (long long) s[0] != c;
        long long best = 1;
        for (long long right = 0; right < n; right++) {
            while (amount > m) {
                left++;
                amount -= (long long) s[left-1] != c;
            }
            best = max(best, right-left+1);
            amount += (long long) s[right+1] != c;
        }
        cout << best << "\n";
    }
}
