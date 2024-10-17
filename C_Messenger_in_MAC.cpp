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

bool comp(pair<ll,ll>& a,pair<ll,ll>& b){
   if(a.ff==b.ff)return a.ss<b.ss;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
return a.ff<b.ff;
}
vector<pair<ll,ll>> vp;
ll a=0;
void dfs(vector<ll>&vis,vector<ll> adj[],ll ind,ll a1,ll b1,ll k,ll c){
    vis[ind]=1;
    a=max(a,c);
   // if(adj[ind].size()==0)return;
    for(auto it:adj[ind]){
        if(vis[it]==0){
            if(a1 + vp[it].ff +abs(b1-vp[it].ss)<=k){
               // vis[it]=1;
                // cout<<ind<<"->"<<endl;
                // display(vis);
                dfs(vis,adj,it,a1+vp[it].ff,vp[it].ss,k,c+1);
               // vis[it]=0;
            }
        }
    }
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
      ll n,l;
      cin>>n>>l;
      for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        vp.pb({a,b});
      }
       sort(vp.begin(),vp.end(),comp);
    //   for(auto it:vp)cout<<it.ff<<" "<<it.ss<<Endl;
    vector<ll> adj[n];
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            if(i==j){
                if(vp[i].ff<=l){
                    adj[i].pb(i);
                }
            }else
            if(vp[i].ff+vp[j].ff+abs(vp[i].ss-vp[j].ss)<=l){
                adj[i].pb(j);
            }
        }
    }
    // for(ll i=0;i<n;i++){
    //     cout<<i<<" -> ";
    //     display(adj[i]);
    // }
    //ll a=-1;
    for(ll i=0;i<n;i++){
        vector<ll> vis(n);
        ll a1=vp[i].ff;
        ll b1=vp[i].ss;
        vis[i]=1;
       if(adj[i].size()) dfs(vis,adj,i,a1,b1,l,1);
    }
    cout<<a<<endl;
    a=0;
    vp.clear();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/