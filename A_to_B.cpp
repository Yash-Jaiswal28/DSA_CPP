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

long long ans(long long x1, long long y1, long long z1, 
               long long x2, long long y2, long long z2, long long K) {
    // Calculate absolute differences in each dimension
    long long dx = abs(x2 - x1);
    long long dy = abs(y2 - y1);
    long long dz = abs(z2 - z1);
    
    // If K is large enough, we can move directly in each dimension
    if (K >= max({dx, dy, dz})) {
        return dx + dy + dz;
    }
    
    long long steps = 0;
    
    // For each dimension
    for (long long dist : {dx, dy, dz}) {
        // Calculate complete sets of K moves needed
        long long complete_sets = dist / K;
        steps += complete_sets * K;
        
        // Calculate remaining distance
        long long remaining = dist % K;
        
        // If there's remaining distance
        if (remaining > 0) {
            // We need to add the remaining distance
            steps += remaining;
            
            // If we used complete sets, we need an extra step to change direction
            if (complete_sets > 0) {
                steps += complete_sets;
            }
        }
        // If we used complete sets but no remainder, we still need steps for direction changes
        else if (complete_sets > 0) {
            steps += complete_sets - 1;
        }
    }
    
    return steps;
}

void solve(){
    int x,y,z,p,q,r,k;
    cin>>x>>y>>z>>p>>q>>r>>k;
    cout<<ans(x,y,z,p,q,r,k)<<endl;
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
      solve();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/