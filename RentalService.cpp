#include <iostream>
#include <cstdio>
#include <algorithm>


using namespace std;

int main() {
    freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);

	long long n, m, r, i;
    cin >> n >> m >> r;
    long long cows[n] = {};
    pair<long long, long long> qpstores[m] = {};
    long long rent[r] = {};
    for (i = 0; i < n; i++) {
        cin >> cows[i];
    }
    sort(cows, cows+n);
    
    for (i = 0; i < m; i++) {
        long long q, p;
        cin >> p >> q;
        qpstores[i] = {q, p};
    }
    sort(qpstores, qpstores+m);
    for (i = 0; i < r; i++) {
        cin >> rent[i];
    }
    sort(rent, rent+r);

    long long ans = 0;

    long long rent_money = 0;

    long long milk_money[n+1] = {};

    for (i = 1; i < n+1; i++) {
        long long more = 0;
        while (cows[n-i] > 0 and m > 0) {
            if (cows[n-i] < qpstores[m-1].second) {
                more += cows[n-i]*qpstores[m-1].first;
                qpstores[m-1].second -= cows[n-i];
                cows[n-i] = 0;
            }
            else {
                cows[n-i] -= qpstores[m-1].second;
                more += qpstores[m-1].second*qpstores[m-1].first;
                m--;
            }
        }
        milk_money[i] = milk_money[i-1]+more;
    }

    for (i = 0; i < min(n+1, r+1); i++) {
        ans = max(ans, milk_money[n-i]+rent_money);
        rent_money += rent[r-1-i];
    }

    cout << ans << "\n";
}
