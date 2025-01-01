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

bool comp(pair<ll,pair<ll,ll>>& a,pair<ll,pair<ll,ll>>& b){
   if(a.ff==b.ff)return a.ss.ff<b.ss.ff;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
return a.ff>b.ff;
}


void solve(){
    ll n,m;
    cin>>n>>m;
    vector<ll> v;
    // v.pb(0);
    Input(v,n);
    // v.pb(n+1);
    unordered_map<ll,ll> mp;
    for(ll i=0;i<n;i++){
        mp[v[i]]=i;
    }
    ll ans=0;
    set<ll> st;
    for(ll i=n-1;i>=0;i--){
        if(st.find(v[i]+1)==st.end()){
            ans++;
        }
        st.insert(v[i]);
    } 
    // cout<<ans<<endl;
    vector<ll> t=v;
    for(ll i=0;i<m;i++){
        ll a,b;
        cin>>a>>b;
        a--;
        b--;
        set<pair<ll,ll>> s;
        if(v[a]+1<=n){
          s.insert({v[a],v[a]+1});
        }
        if(v[a]-1>0){
          s.insert({v[a]-1,v[a]});
        }
        if(v[b]+1<=n){
          s.insert({v[b],v[b]+1});
        }
        if(v[b]-1>0){
          s.insert({v[b]-1,v[b]});
        }
        for(auto it:s){
          ans-=mp[it.ff]>mp[it.ss];
        }
        mp[v[a]]=b;
        mp[v[b]]=a;
        swap(v[a],v[b]);
        for(auto it:s){
          ans+=mp[it.ff]>mp[it.ss];
        }
        cout<<ans<<Endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
//   ll t;
//   cin>>t;
//     for(ll Z=0;Z<t;Z++)
    {
      solve();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/