#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int main() {
	long long n, l;
    cin >> n >> l;
    long long lanterns[n+2] = {};
    for (long long i=0; i < n; i++) {
        cin >> lanterns[i];
    }
    sort(lanterns, lanterns+n);
    long long dif = 0;
    for (long long i=0; i < n-1; i++) {
        dif = max(dif, lanterns[i+1]-lanterns[i]);
    }
    if (2*lanterns[0] >= dif) {
        dif = 2*lanterns[0];
    }
    if (2*(l-lanterns[n-1]) >= dif) {
        dif = 2*(l-lanterns[n-1]);
    }
    if (dif % 2 == 0) {
        cout << dif/2 << "\n";
    }
    else {
        cout << dif/2 << ".5\n";
    }
}
