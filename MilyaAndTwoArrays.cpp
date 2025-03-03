#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    long long t;
    cin >> t;
    for (long long q = 0; q < t; q++) {
        long long n;
        cin >> n;
        set<long long> a = {};
        set<long long> b = {};
        for (long long i = 0; i < n; i++) {
            long long test;
            cin >> test;
            a.insert(test);
        }
        for (long long i = 0; i < n; i++) {
            long long test;
            cin >> test;
            b.insert(test);
        }
        if (a.size()>=3 or b.size()>=3) {
            cout << "Yes" << endl;
        }
        else if (a.size()==1 or b.size()==1) {
            cout << "No" << endl;
        }
        else {
            set<long long> sums = {};
            for (long long ai : a) {
                for (long long bi : b) {
                    sums.insert(ai+bi);
                }
            }
            if (sums.size() >= 3) {
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}
