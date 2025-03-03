#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exponent) {
    long long result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) {
            result *= base;
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, x;
        cin >> n >> x;
        if (x == 0) {
            for (long long i = 0; i < n; i++) {
                cout << 0 << " ";
            }
            cout << "\n";
        }
        else {
            bitset<32> binary(x);
            string binaryString = binary.to_string();
            binaryString = binaryString.substr(binaryString.find('1'));
            long long first = -1;
            for (long long i = 0; i < binaryString.size(); i++) {
                if (binaryString[binaryString.size()-1-i] == '0') {
                    first = i;
                    break;
                }
            }
            if (first == -1) {
                if (x+1 <= n) {
                    for (long long i = 0; i < x+1; i++) {
                        cout << i << " ";
                        n--;
                    }
                    for (long long i = 0; i < n; i++) {
                        cout << x << " ";
                    }
                }
                else {
                    for (long long i = 0; i < n-1; i++) {
                        cout << i << " ";
                    }
                    if ((x+1)/2 <= n-1) {
                        cout << n-1 << " ";
                    }
                    else {
                        cout << x << " ";
                    }
                }
                cout << "\n";
            }
            else {
                n--;
                cout << x << " ";
                long long result = power(2, first);
                long long small = min(n, result);
                for (long long i = 0; i < small; i++) {
                    cout << i << " ";
                    n--;
                }
                for (long long i = 0; i < n; i++) {
                    cout << x << " ";
                }
                cout << "\n";
            }
        }
    }
}
