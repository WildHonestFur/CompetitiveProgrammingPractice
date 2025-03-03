#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
    freopen("paintbarn.in", "r", stdin);
	freopen("paintbarn.out", "w", stdout);
    
    long n, k;
    cin >> n >> k;
    long arr[1001][1001] = {};
    long i, j;
    
    for (i = 0; i<n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        arr[x1][y1] += 1;
        arr[x2][y2] += 1;
        arr[x1][y2] -= 1;
        arr[x2][y1] -= 1;
    }
    
    long ans = 0;
    long pre[1001][1001] = {};
    
    for (i = 1; i<1001; i++) {
        for (j = 1; j<1001; j++) {
            pre[j][i] = pre[j][i-1]+pre[j-1][i]-pre[j-1][i-1]+arr[j-1][i-1];
            if (pre[j][i] == k) {
                ans += 1;
            }
        }
    }
    cout << ans << "\n";
    
    return 0;
}