#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, k;
        cin >> n >> k;
        cout << ((k-1)/(n-1))+k << "\n";
    }
}
