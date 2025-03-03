#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        long long n, a, b;
        cin >> n >> a >> b;
        if (abs(a-b) % 2 == 0) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
}
