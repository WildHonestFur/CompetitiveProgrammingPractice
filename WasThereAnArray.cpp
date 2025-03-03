#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n;
        cin >> n;
        long long b[n-2] = {};
        bool good = true;
        for (long long j = 0; j < n-2; j++) {
            cin >> b[j];
            if (j > 1) {
                if (b[j] == 1 and b[j-2] == 1 and b[j-1] == 0) {
                    good = false;
                }
            }
        }
        if (good) {
            cout << "YES" << "\n";
        }
        else {
            cout << "NO" << "\n";
        }
    }
}
