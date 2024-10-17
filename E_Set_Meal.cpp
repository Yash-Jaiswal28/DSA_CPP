//Marcellus
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"YES"<<Endl
#define no cout<<"NO"<<Endl
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

bool comp(pair<ll,pair<ll,ll>> a,pair<ll,pair<ll,ll>> b){
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
       
//   ll t;
//   cin>>t;
//     for(ll Z=0;Z<t;Z++)
    {
      ll n,m,q;
      cin>>n>>m>>q;
      vector<pair<ll,ll>> v1,v2;
      for(ll i=0;i<n;i++){
        ll e;
        cin>>e;
        v1.pb({e,i});
      }
      for(ll i=0;i<m;i++){
        ll e;
        cin>>e;
        v2.pb({e,i});
      }
      vector<pair<ll,ll>> t1=v1,t2=v2;
      sort(t1.begin(),t1.end());
      sort(t2.begin(),t2.end());
      map<ll,ll> mp1,mp2;
      set<pair<ll,ll>> s1,s2;
      mp1[-1]=0;
      mp2[-1]=0;
      ll c=-(m+n);
      for(ll i=n-1;i>=0 && c<=q;i--){
        for(ll j=m-1;j>=0 && c<=q;j--){
            c++;
            s1.insert({t1[i].ss,t2[j].ss});
            mp1[t1[i].ff+t2[j].ff]++;
        }
        if(c<=q)t1.pop_back();
      }
      c=-(n+m);
      ll t=t1.size();
      for(ll j=m-1;j>=0 && c<=q;j--){
        for(ll i=t-1;i>=0 && c<=q;i--){
            c++;
            s2.insert({t1[i].ss,t2[j].ss});
            mp2[t1[i].ff+t2[j].ff]++;
        }
      }
      //cout<<mp1.size()<<" "<<mp2.size()<<Endl;
      for(ll i=0;i<q;i++){
        ll a,b;
        cin>>a>>b;
        a--,b--;
        if(s1.find({a,b})!=s1.end()){
            mp1[v1[a].ff+v2[b].ff]--;
        }
        if(s2.find({a,b})!=s2.end()){
            mp2[v1[a].ff+v2[b].ff]--;
        }
        if(mp1[v1[a].ff+v2[b].ff]<=0){
            mp1.erase(v1[a].ff+v2[b].ff);
        }
        if(mp2[v1[a].ff+v2[b].ff]<=0){
            mp2.erase(v1[a].ff+v2[b].ff);
        }
      }
       //cout<<mp1.size()<<" "<<mp2.size()<<endl;
       cout<<max((--mp1.end())->first,(--mp2.end())->first)<<Endl;
    // ll a=INT_MIN;
    // ll b=INT_MIN;
    // auto it1 =mp1.rbegin();
    // auto it2=mp2.rbegin();
    // cout<<it1->ff<<" "<<it2->ff<<Endl;
    // for(auto it: mp1)cout<<it.ff<<" ";
    // cout<<Endl;
    // for(auto it:mp2)cout<<it.ff<<" ";
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/