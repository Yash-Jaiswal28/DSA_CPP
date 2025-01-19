#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define ll long long
#define ff first
#define ss second
#define pb push_back

template <typename T>
using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool comp(const pair<pair<ll, ll>, ll>& p1, const pair<pair<ll, ll>, ll>& p2) {
    if (p1.ff.ff == p2.ff.ff)
        return p1.ff.ss > p2.ff.ss; // Sort by end in descending order if start is equal
    return p1.ff.ff < p2.ff.ff;    // Otherwise, sort by start in ascending order
}

void display(const vector<ll>& v) {
    for (ll x : v) {
        cout << x << " ";
    }
    cout << "\n";
}

void solve() {
    ll n;
    cin >> n;

    vector<pair<pair<ll, ll>, ll>> vp;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        vp.pb({{a, b}, i});
    }

    // Sort intervals
    sort(vp.begin(), vp.end(), comp);

    // Forward pass: Count intervals fully contained
    vector<ll> v1(n);
    ordered_set<ll> s;
    for (auto it : vp) {
        ll r = it.ff.ss;

        // Count intervals in the set with an endpoint >= r
        ll x = s.size() - s.order_of_key(r);
        v1[it.ss] = x;

        // Insert the endpoint into the ordered set
        s.insert(r);
    }

    // Reverse pass: Count intervals that fully contain
    vector<ll> v2(n);
    ordered_set<ll> s1;
    for (ll i = n - 1; i >= 0; i--) {
        ll r = vp[i].ff.ss;

        // Count intervals in the set with an endpoint > r
        ll x = s1.order_of_key(r + 1);
        v2[vp[i].ss] = x;

        // Insert the endpoint into the ordered set
        s1.insert(r);
    }

    // Display results
    display(v2); // Intervals that fully contain
    display(v1); // Intervals fully contained
}


int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
  // ll t;
  // cin>>t;
  //   for(ll Z=0;Z<t;Z++)
    {
      solve();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/