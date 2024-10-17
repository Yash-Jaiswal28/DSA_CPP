#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#define ff first
#define ss second
using namespace std;

typedef long long ll;

bool comp(pair<ll, pair<ll, ll>> a, pair<ll, pair<ll, ll>> b)
{
  if (a.ff == b.ff)
    return a.ss.ff < b.ss.ff;
  return a.ff > b.ff;
}

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  ll t;
  cin >> t;

  for (ll Z = 0; Z < t; Z++)
  {
    ll n;
    cin >> n;

    vector<pair<ll, ll>> vp;
    for (ll i = 0; i < n; i++)
    {
      ll a, b;
      cin >> a >> b;
      vp.push_back({a, b});
    }

    ll l1 = 0, r1 = LLONG_MAX; // Changed INT_MAX to LLONG_MAX
    ll minK = LLONG_MAX;       // Initialize with the maximum possible value

    while (l1 <= r1)
    {
      ll m = l1 + (r1 - l1) / 2;
      ll last1 = 0, last2 = 0;
      ;
      bool possible = true;
      //    cout<<"->"<<endl;
      for (auto it : vp)
      {
        last1 -= m;
        last2 += m;
        if (last2 < it.ff || last1 > it.ss)
          possible = false;
        else
        {
          last1 = max(last1, it.ff);
          last2 = min(last2, it.ss);
        }
      }

      if (possible)
      {
        // If completing the level, update the minimum k and continue searching for smaller k
        minK = m;
        r1 = m - 1;
      }
      else
      {
        // If not possible, increase k
        l1 = m + 1;
      }
    }

    cout << minK << endl;
  }

  return 0;
}
