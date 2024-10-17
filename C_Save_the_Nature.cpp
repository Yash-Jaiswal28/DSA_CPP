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
      ll n;
      cin>>n;
      vector<ll> v;
      Input(v,n);
      sort(v.rbegin(),v.rend());
      ll x,y,a,b,k;
      cin>>x>>a>>y>>b>>k;
      if(y>x){
        swap(x,y);
        swap(a,b);
      }
      ll lcm=(a*b)/__gcd(a,b);
      ll l=1,h=n,ans=-1;
      while(l<=h){
        ll mid=(l+h)/2;
        ll m=0;
        ll sum=0;
        vector<ll> t(mid,0);
        for(ll i=lcm-1;i<mid;i+=lcm){
            t[i]=v[m];
            sum+=(v[m]/100)*(x+y);
            m++;
        }
        for(ll i=a-1;i<mid;i+=a){
           if(t[i]==0){ 
            t[i]=v[m];
            sum+=(v[m]/100)*(x);
            m++;
           }
        }
        for(ll i=b-1;i<mid;i+=b){
           if(t[i]==0){
             t[i]=v[m];
            sum+=(v[m]/100)*(y);
            m++;
           }
        }
        if(sum>=k){
            ans=mid;
            h=mid-1;
        }else l=mid+1;
      }
      cout<<ans<<endl;
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/