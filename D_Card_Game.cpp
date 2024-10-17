// Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
#define ff first
#define ss second
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e9 + 7;
template <class T>
void display(vector<T> &v)
{
  for (ll i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
template <class U>
void display(vector<vector<U>> &v)
{
  for (ll i = 0; i < v.size(); i++)
  {
    for (ll j = 0; j < v[i].size(); j++)
    {
      cout << v[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}
template <class V>
void Input(vector<V> &v, ll n)
{
  for (ll i = 0; i < n; i++)
  {
    V element;
    cin >> element;
    v.pb(element);
  }
}
template <class W>
void Input(vector<vector<W>> &v, ll n, ll m)
{
  v.resize(n, vector<W>(m));
  for (ll i = 0; i < n; i++)
  {
    for (ll j = 0; j < m; j++)
    {
      W element;
      cin >> element;
      v[i].pb(element);
    }
  }
}
ll Pow(ll a, ll b)
{
  ll c = b, d = a;
  ll ans = 1;
  while (c)
  {
    if (c & 1)
    {
      ans = ((d % mod) * (ans % mod)) % mod;
    }
    d = ((d % mod) * (d % mod)) % mod;
    c >>= 1;
  }
  return ans;
}
ll fact(ll n)
{
  if (n <= 2)
    return n;
  else
  {
    ll a = 1;
    for (ll i = 2; i <= n; i++)
    {
      a = ((a % mod) * (i % mod)) % mod;
    }
    return a;
  }
}
ll nCr(ll n, ll r)
{
  ll res = 1;
  for (ll i = r + 1; i <= n; i++)
  {
    res = (res * i) % mod;
  }
  ll inv = 1;
  for (ll i = 2; i <= n - r; i++)
  {
    inv = (inv * i) % mod;
  }
  inv = Pow(inv, mod - 2);
  return (res * inv) % mod;
}
ll nPr(ll n, ll r)
{
  ll d = fact(n);
  ll c = fact(n - r);
  return (d / c);
}

/*********************************************************************************************************************************************************************************************************/

bool comp(pair<ll, pair<ll, ll>> &a, pair<ll, pair<ll, ll>> &b)
{
  if (a.ff == b.ff)
    return a.ss.ff < b.ss.ff;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
  return a.ff > b.ff;
}

int main()
{
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);
  //     #endif

  ll t;
  cin >> t;
  for (ll Z = 0; Z < t; Z++)
  {
    ll n;
    cin >> n;
    char s[1];
    cin >> s[0];
    map<char, set<char>> mp;
    for (ll i = 0; i < 2 * n; i++)
    {
      string t;
      cin >> t;
      mp[t[1]].insert(t[0]);
    }
    vector<pair<string, string>> vp;
    ll d = 0;
    for (auto& it : mp)
    {
      if (it.ff != s[0])
      {
        if (it.ss.size() > 0)
        {
          if (it.ss.size() == 1)
          {
            if (mp[s[0]].size() == 0)
            {
              d = 1;
              // cout << "empty"
              //      << " ";
              break;
            }
            else
            {
              string t1;
              t1.pb(*(it.ss.begin()));
              t1.pb(it.ff);
              string t2;
              t2.pb(*(mp[s[0]].begin()));
              t2.pb(s[0]);
              vp.pb({t1, t2});
              // cout << "1-- " << t1 << " " << t2 << endl;
              it.ss.erase(((it.ss.begin())));
              cout<<*mp[s[0]].begin()<<" ";
              mp[s[0]].erase(mp[s[0]].begin());
              cout<<*mp[s[0]].begin()<<" ";
            }
          }
          else
          {
            string t1, t2;

            t1.pb(*(it.ss.begin()));
            t1.pb(it.ff);
            it.ss.erase(it.ss.begin());

            t2.pb(*(it.ss.begin()));
            t2.pb(it.ff);
            it.ss.erase(it.ss.begin());

            // cout << "2--- " << t1 << " " << t2 << endl;
            vp.pb({t1, t2});
          }
        }
      }
      // for(auto it:vp){
      //             cout<<it.ff<<" "<<it.ss<<endl;
      //         }
    }
   // for(auto it:mp[s[0]])cout<<it<<' ';
    if (mp[s[0]].size() & 1)
      d = 1;
    // cout << "extra  ";
    if (mp[s[0]].size())
    {
      string temp;
      for (auto it : mp[s[0]])
        temp.pb(it);
      for (ll i = 0; i < temp.size() - 1; i += 2)
      {
        string t1, t2;     // Declare two strings t1 and t2
        t1 += temp[i];     // Append temp[i] to t1
        t1 += s[0];        // Append the first character of string s to t1
        t2 += temp[i + 1]; // Append temp[i+1] to t2
        t2 += s[0];        // Append the first character of string s to t2
        vp.pb({t1, t2});
      }
    }
    // cout<<"IMPOSSIBLE"<<endl;
    if (d)
      cout << "IMPOSSIBLE" << endl;
    else
    {
      for (auto it : vp)
      {
        cout << it.ff << " " << it.ss << endl;
      }
    }
  }
}
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/