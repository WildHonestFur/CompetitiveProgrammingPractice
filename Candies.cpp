#include <iostream>
#include <cstdio>

using namespace std;

int main() {
	int t;
    cin >> t;
    int k;
    for (k = 0; k < t; k++) {
        long long sum = 0;
        long n, q, i, j;
        cin >> n >> q;
        int arr[n+1] = {};
        long pre_mult[n+1] = {};
        long pre_const[n+1] = {};
        for (i = 1; i < n+1; i++) {
            int a;
            cin >> a;
            arr[i] = a;
            int val = arr[i];
            if (i % 2 == 0) {
                val *= -1;
            }
            pre_mult[i] = pre_mult[i-1] + val*i;
            pre_const[i] = pre_const[i-1] + val;
        }

        for (j = 0; j < q; j++) {
            string op;
            long x;
            int y;
            cin >> op >> x >> y;

            if (op == "U") {
                arr[x] = y;
                for (i = 1; i < n+1; i++) {
                    int val = arr[i];
                    if (i % 2 == 0) {
                        val *= -1;
                    }
                    pre_mult[i] = pre_mult[i-1] + val*i;
                    pre_const[i] = pre_const[i-1] + val;
                }
            }
            else {
                long pre_sum = pre_mult[y]-pre_mult[x-1];
                long pre_sub = (x-1)*(pre_const[y]-pre_const[x-1]);
                if (x % 2 == 1) {
                    sum += pre_sum-pre_sub;
                }
                else {
                    sum -= pre_sum-pre_sub;
                }
            }
        }

        cout << "Case #" << k+1 << ": "  << sum << "\n";
    }
}
