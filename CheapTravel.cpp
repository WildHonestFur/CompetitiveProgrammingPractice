#include <bits/stdc++.h>
using namespace std;

int main() {
	long long n, m, a, b;
    cin >> n >> m >> a >> b;
    if (a*m <= b) {
        cout << n*a << "\n";
    }
    else {
        long long ans = (n/m)*b;
        long long remain = n % m;
        if (remain == 0) {
            cout << ans << "\n";
        }
        else {
            cout << ans + min(b, remain*a) << "\n";
        }
    }
}
