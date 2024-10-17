//Marcellus
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
      vector<ll> v,v1,v2(n);
      Input(v,n);
      ll a=1;
      v1.pb(0);
      v1.pb(1);
      for(ll i=1;i<n-1;i++){
        if(v[i]-v[i-1]<v[i+1]-v[i]){
            //cout<<"<- ";
            v1.pb(v1.back()+v[i+1]-v[i]);
        }else{
           // cout<<"-> ";
            v1.pb(v1.back()+1);
        }
      }
      cout<<endl;
      v2[n-2]=1;
      for(ll i=n-2;i>0;i--){
        if(abs(v[i]-v[i-1])>abs(v[i+1]-v[i])){
            a+=abs(v[i]-v[i-1]);
           // cout<<abs(v[i]-v[i-1])<<" -> ";
        }else{
           // cout<<"1 <- ";
            a+=1;
        }
        v2[i-1]=a;
      }
    //   cout<<Endl;
    //   display(v);
    //   display(v1);
    //   display(v2);
      ll m;
      cin>>m;
      for(ll i=0;i<m;i++){
        ll p,q;
        cin>>p>>q;
        if(p<q){
            cout<<v1[q-1]-v1[p-1]<<endl;
        }else{
            cout<<v2[q-1]-v2[p-1]<<Endl;
        }
      } 
      
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/