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
    vector<ll> v1,v2;
    Input(v1,n);
    Input(v2,m);
    sort(v1.begin(),v1.end());
    ll l=0,h=INT_MAX;
    ll ans=LLONG_MAX;
    while(l<=h){
        ll r=(l+h)/2;
        ll mn=lower_bound(v1.begin(),v1.end(),v2[0]-r)-v1.begin(),mx=upper_bound(v1.begin(),v1.end(),v2[0]+r)-v1.begin();
        mx--;
        ll c=0;
        for(ll i=0;i<m;i++){
            ll ind1=lower_bound(v1.begin(),v1.end(),v2[i]-r)-v1.begin();
            ll ind2=upper_bound(v1.begin(),v1.end(),v2[i]+r)-v1.begin();
            ind2--;
            if(mx+1<ind1){
                c=1;
                break;
            }else{
               // cout<<ind1<<" "<<ind2<<Endl;
                mx=ind2;
               // mn=ind1;
            }
        }
        if(mx<n-1 || mn!=0)c=1;
        if(c){
            l=r+1;
        }else {
            //cout<<mn<<"->"<<mx<<"   "<<r<<Endl;
            ans=r;
            h=r-1;
        }
    }
    cout<<ans;
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