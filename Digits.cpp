#include <bits/stdc++.h>
using namespace std;

int main() {
	long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n, d;
        cin >> n >> d;
        vector<int> vals = {1};
        if (d == 5) {
            vals.push_back(5);
        }
        if (d % 3 == 0 or n > 2) {
            vals.push_back(3);
        }
        if (d % 9 == 0 or n > 5 or (d % 3 == 0 and n > 2)) {
            vals.push_back(9);
        }
        if (d % 7 == 0 or n > 2) {
            vals.push_back(7);
        }
        sort(vals.begin(), vals.end());
        for (int i = 0; i < vals.size(); i++) {
            cout << vals[i] << " ";
        }
        cout << "\n";
    }
}
