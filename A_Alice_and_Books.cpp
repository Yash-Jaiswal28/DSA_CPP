#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

void Input(vector<ll>& v, ll n) {
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        v.push_back(x);
    }
}

void solve() {
    ll n;
    cin >> n;
    vector<ll> v;
    Input(v, n);
    vector<ll> t = v;
    sort(t.begin(), t.end());
    ll maxOrig = v[n - 1];
    ll maxSorted = t[n - 1];
    if (maxOrig == maxSorted) {
        cout << maxSorted + t[n - 2] << endl;
    } else {
        cout << maxOrig + maxSorted << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    for (ll Z = 0; Z < t; Z++) {
        solve();
    }
    return 0;
}