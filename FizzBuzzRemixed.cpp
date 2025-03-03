#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        long long k = n/15;
        long long l = min(n % 15 + 1, (long long) 3);
        cout << k*3 + l << "\n";
    }
}
