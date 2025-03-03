#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q; q < t; q++) {
        long long n;
        cin >> n;
        long long odds = 0;
        long long evens = 0;
        for (long long i = 0; i < n; i++) {
            long long a;
            cin >> a;
            if (a % 2 == 0) {
                evens++;
            }
            else {
                odds++;
            }
        }
        if (evens == 0) {
            cout << odds-1 << "\n";
        }
        else {
            cout << odds+1 << "\n";
        }
    }
}
