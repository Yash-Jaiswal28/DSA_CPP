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
      vector<vector<char>> v(2,vector<char>());
      Input(v,2,n);
      vector<vector<ll>> vis1(2,vector<ll>(n,0)),vis2(2,vector<ll>(n,0));
      queue<pair<ll,ll>> q1,q2;
      q2.push({0,0});
      ll a=0;
      while(q1.size() || q2.size()){
       if(q2.size()){
        auto it1=q2.front();
        q2.pop();
        // cout<<"1-->"<<endl;
        // cout<<it1.ff<<" "<<it1.ss<<endl;
        if(it1.ss+1==n){
          a=1;
          break;
        }
        if(vis1[it1.ff][it1.ss+1]==0)q1.push({it1.ff,it1.ss+1});
        if(vis1[1-it1.ff][it1.ss+1]==0)q1.push({(1-it1.ff),it1.ss});
        vis1[it1.ff][it1.ss+1]=1;
        vis1[1-it1.ff][it1.ss]=1;
       }
        auto it=q1.front();
        q1.pop();
        // cout<<"2-->"<<endl;
        // cout<<it.ff<<" "<<it.ss<<Endl;
        if(v[it.ff][it.ss]=='>'){
          if(vis2[it.ff][it.ss+1]==0)q2.push({it.ff,it.ss+1});
          vis2[it.ff][it.ss+1]=1;
        }
      }
      if(a)yes;
      else no;
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/