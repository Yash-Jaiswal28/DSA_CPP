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
ll Pow(ll a,ll b){ll c=b,d=a;ll ans=1;while(c){if(c&1){ans=((d%mod)*(ans%mod))%mod;} d=((d%mod)*(d%mod))%mod;c>>=1;}return ans;}
ll fact(ll n){if(n<=2)return n;else{ll a=1;for(ll i=2;i<=n;i++){a=((a%mod)*(i%mod))%mod;}return a;}}
ll nCr(ll n, ll r) {ll res = 1;for (ll i = r+1; i <= n; i++){res = (res * i) % mod;}ll inv = 1;for (ll i = 2; i <= n-r; i++){inv = (inv * i) % mod;}inv = Pow(inv, mod-2);return (res * inv) % mod;}
ll nPr(ll n,ll r){ll d=fact(n);ll c=fact(n-r);return (d/c);}


/*********************************************************************************************************************************************************************************************************/

bool comp(pair<ll,pair<ll,ll>>& a,pair<ll,pair<ll,ll>>& b){
   if(a.ff==b.ff)return a.ss.ff<b.ss.ff;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
return a.ff>b.ff;
}




int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
  ll t;
  cin>>t;
    for(ll Z=0;Z<t;Z++)
    {
      ll n,k,ind1,ind2;
      cin>>n>>k>>ind1>>ind2;
      ind1--;
      ind2--;
      vector<ll> v1,v2;
      Input(v1,n);
      Input(v2,n);
      vector<ll> t1,t2;
      for(ll i=0;i<n;i++){
        t1.pb(v2[ind1]);
        ind1=v1[ind1]-1;
        t2.pb(v2[ind2]);
        ind2=v1[ind2]-1;
      }
      ll s=0;
      ll prev=0;
      for(ll i=0;i<min(n,k);i++){
        prev=max(prev,s+t1[i]*(k-i));
        s+=t1[i];
      }
      ll s1=0;
      ll prev1=0;
      for(ll i=0;i<min(n,k);i++){
        prev1=max(prev1,s1+t2[i]*(k-i));
        s1+=t2[i];
      }
      if(prev>prev1)cout<<"Bodya"<<endl;
      else if(prev<prev1)cout<<"Sasha"<<endl;
      else cout<<"Draw"<<endl;
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/