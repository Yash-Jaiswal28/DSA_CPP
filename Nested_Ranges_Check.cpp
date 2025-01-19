//Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
const ll mod = 1e9 + 7;
template <class T> void display(vector<T> &v){ for(ll i=0;i<v.size();i++){cout<<v[i]<<" ";}cout<<endl;}
template <class U> void display(vector<vector<U>> &v){for(ll i=0;i<v.size();i++){for(ll j=0;j<v[i].size();j++){cout<<v[i][j]<<" ";}cout<<endl;} cout<<endl;}
template <class V> void Input(vector<V> &v,ll n){for(ll i=0;i<n;i++){V element;cin>>element;v.pb(element);}}
template <class W> void Input(vector<vector<W>> &v, ll n, ll m){v.resize(n, vector<W>(m));for(ll i = 0; i < n; i++){for(ll j = 0; j < m; j++){W element;cin >> element;v[i].pb(element);}}}
ll Pow(ll base,ll ex){ll ans=1ll;while(ex>0){if(ex%2==1)ans=(ans*base)%mod;ex=ex/2;base=(base*base)%mod;}return ans;}
ll fact(ll n){if(n<=2)return n;else{ll a=1;for(ll i=2;i<=n;i++){a=((a%mod)*(i%mod))%mod;}return a;}}
ll nCr(ll n, ll r){if(r>n)return 0;ll res = 1;for (ll i = r+1; i <= n; i++){res = (res * i) % mod;}ll inv = 1;for (ll i = 2; i <= n-r; i++){inv = (inv * i) % mod;}inv = Pow(inv, mod-2);return (res * inv) % mod;}
ll nPr(ll n,ll r){ll d=fact(n);ll c=fact(n-r);return (d/c);}


/*********************************************************************************************************************************************************************************************************/

bool comp(pair<pair<ll,ll>,ll>& a,pair<pair<ll,ll>,ll>& b){
   if(a.ff.ff==b.ff.ff)return a.ff.ss>b.ff.ss;
   return a.ff.ff<b.ff.ff;
}


void solve(){
  ll n;
  cin>>n;
  vector<pair<pair<ll,ll>,ll>> vp;
  for(ll i=0;i<n;i++){
    ll a,b;
    cin>>a>>b;
    vp.pb({{a,b},i});
  }
  sort(vp.begin(),vp.end(),comp);
  vector<ll> v1(n);
  ll l=-1,r=-1;
  for(auto it:vp){
    if(it.ff.ss>r){
      r=it.ff.ss;
    }else{
      v1[it.ss]=1;
    }
  } 
  l =INT_MAX;
  vector<ll> v2(n);
  for(ll i=n-1;i>=0;i--){
    if(l<=vp[i].ff.ss){
      v2[vp[i].ss]=1;
    }
    l=min(l,vp[i].ff.ss);
  }
  display(v2);
  display(v1);
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