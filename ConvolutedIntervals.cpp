#include <bits/stdc++.h>
using namespace std;

int main() {
	long n;
    int m;
    cin >> n >> m;
    long k[2*m+2] = {};
    long freqa[m+1] = {};
    long freqb[m+1] = {};
    long i, j;

    for (i=0; i< n; i++) {
        int x, y;
        cin >> x >> y;
        freqa[x] += 1;
        freqb[y] += 1;
    }
    for (i=0; i< m+1; i++) {
        for (j=i+1; j< m+1; j++) {
            k[i+j] += 2*freqa[i]*freqa[j];
            k[i+j+1] -= 2*freqb[i]*freqb[j];
        }
        k[2*i] += freqa[i]*freqa[i];
        k[2*i+1] -= freqb[i]*freqb[i];
    }

    long pre_k[2*m+2] = {};

    for (i = 1; i < 2*m+2; i++) {
        pre_k[i] = pre_k[i-1]+k[i-1];
        cout << pre_k[i] << "\n";
    }
}
