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


void solve(){
    ll n;
    cin>>n;
    map<ll,vector<ll>> mp1,mp2;
    vector<pair<ll,ll>> vp;
    map<pair<ll,ll>,ll> mp;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        vp.pb({a,b});
        mp1[a].pb(i);
        mp2[b].pb(i);
        mp[{a,b}]++;
    }
    ll f=0;
    set<ll> s1,s2;
    for(auto it:vp){
        if((mp1[it.ff].size()>=2 && mp2[it.ss].size()>2) || (mp1[it.ff].size()>2 && mp2[it.ss].size()>=2)){
            set<ll> tp;
            for(auto it1:mp1[it.ff])tp.insert(it1);
            for(auto it1:mp2[it.ss])tp.insert(it1);
            if(tp.size()<mp1[it.ff].size()+mp2[it.ss].size()){
            if(s1.find(it.ff)==s1.end() && s2.find(it.ss)==s2.end()){
                s1.insert(it.ff);
                s2.insert(it.ss);
                cout<<it.ff<<" "<<it.ss<<Endl;
                f++;
            }
        }
        }
        //cout<<it.ff<<" "<<it.ss<<endl;
    }
    if(f&1){
        cout<<"Takahashi"<<endl;
        return;
    }
    else {
        cout<<"Aoki"<<endl;
        return ;
    }
    ll c=0;
    for(auto it:vp){
        c+=mp1[it.ff].size()/2+mp2[it.ss].size()/2;
    }
    //cout<<c<<Endl;
    if(c&1)cout<<"Takahashi"<<endl;
    else cout<<"Aoki"<<endl;
    return ;
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