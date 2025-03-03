#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        string a;
        cin >> a;
        for (long long i = 0; i < a.size(); i++) {
            if (a[a.size()-1-i] == 'w') {
                cout << 'w';
            }
            else if (a[a.size()-1-i] == 'p') {
                cout << 'q';
            }
            else{
                cout << 'p';
            }
        }
        cout << '\n';
    }
}
