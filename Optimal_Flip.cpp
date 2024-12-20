#include <bits/stdc++.h>

using namespace std;
#define ll long long

int main() {
    // your code goes here

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll A[n];
        ll oddCount = 0;

        for (ll i = 0; i < n; i++) {
            cin >> A[i];
            if (A[i] % 2 != 0) {
                ++oddCount;
            }
        }
        
        ll ans = (n * (n + 1)) / 2;
        ll maxConsecutiveOdd = 0;

        if (oddCount <= 1) {
            cout << ans << endl;
        } else {

            ll c = 0;
            for (ll i = 0; i < n; i++) {
                if (A[i] % 2 != 0) {
                    c++;
                    maxConsecutiveOdd = max(maxConsecutiveOdd, c);
                } else {
                    ans -= (c * (c + 1)) / 2;
                    c = 0;
                }
            }
            ans -= (c * (c + 1)) / 2;
        }

        ll i = 1;
        ll j = maxConsecutiveOdd;
        ll d = 1;

        while (i < j) {
            ans += (2 * d);
            d++;
            i++;
            j--;

        }

        if (i == j) ans += d;

        cout << ans << endl;

    }

}