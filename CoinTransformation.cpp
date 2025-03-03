#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;
    for (long long i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long count = 0;
        long long val;
        cin >> val;
        while (val > 3) {
            count += 1;
            val /= 4;
        }
        cout << power(2, count) << "\n";
    }
}
