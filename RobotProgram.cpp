#include <bits/stdc++.h>
#include <algorithm>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, x, k;
        cin >> n >> x >> k;
        long long firstzero = -1;
        long long pre[n+1] = {};
        long long zero = -1;
        for (long long i = 0; i < n; i++) {
            char command;
            cin >> command;
            if (command == 'L') {
                pre[i+1] = pre[i]-1;
            }
            else {
                pre[i+1] = pre[i]+1;
            }
            if (pre[i+1] + x == 0 and firstzero == -1) {
                firstzero = i+1;
            }
            else if (pre[i+1] == 0 and zero == -1) {
                zero = i+1;
            }            
        }
        if (firstzero > 0) {
            if (firstzero > k) {
                cout << 0 << "\n";
            }
            else {
                if (zero > 0) {
                    long long extra = (k-firstzero)/zero + 1;
                    cout << extra << "\n";
                }
                else {
                    cout << 1 << "\n";
                }
            }
        }
        else {
            cout << 0 << "\n";
        }        
    }
}
