#include <iostream>
#include <cstdio>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long x, y;
        cin >> x >> y;
        long long value = x+1-y;
        if (value >= 0 and value % 9 == 0) {
            cout << "Yes" << "\n";
        }
        else {
            cout << "No" << "\n";
        }
    }
}