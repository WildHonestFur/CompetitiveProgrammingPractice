#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long m, n;
        cin >> m >> n;
        cout << max(m, n)+1 << "\n";
    }
}