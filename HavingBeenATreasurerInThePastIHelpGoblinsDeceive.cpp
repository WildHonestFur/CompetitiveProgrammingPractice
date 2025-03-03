#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long under = 0, dash = 0;
        for (long long i = 0; i < n; i++) {
            char c;
            cin >> c;
            if (c == '_') {
                under++;
            }
            else {
                dash++;
            }
        }
        long long right = dash/2;
        long long left = dash-right;
        cout << under*right*left << "\n";
    }
}
