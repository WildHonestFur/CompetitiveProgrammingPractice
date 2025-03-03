#include <bits/stdc++.h>
using namespace std;

int main() {
	string x;
    cin >> x;
    map<char, char> digits;
    digits['0'] = '0';
    digits['1'] = '1';
    digits['2'] = '2';
    digits['3'] = '3';
    digits['4'] = '4';
    digits['5'] = '4';
    digits['6'] = '3';
    digits['7'] = '2';
    digits['8'] = '1';
    digits['9'] = '0';

    for (long i = 0; i < x.size(); i++) {
        if (i == 0 and x[i] == '9') {
            cout << x[i];
        }
        else {
            cout << digits[x[i]];
        }
    }
    cout << "\n";
}
