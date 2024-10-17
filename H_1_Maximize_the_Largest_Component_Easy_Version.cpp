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
ll nCr(ll n, ll r) {ll res = 1;for (ll i = r+1; i <= n; i++){res = (res * i) % mod;}ll inv = 1;for (ll i = 2; i <= n-r; i++){inv = (inv * i) % mod;}inv = Pow(inv, mod-2);return (res * inv) % mod;}
ll nPr(ll n,ll r){ll d=fact(n);ll c=fact(n-r);return (d/c);}


/*********************************************************************************************************************************************************************************************************/

bool comp(pair<ll,pair<ll,ll>>& a,pair<ll,pair<ll,ll>>& b){
   if(a.ff==b.ff)return a.ss.ff<b.ss.ff;
  // if(a.ss.ff==b.ss.ff)return a.ss.ff<b.ss.ff;
return a.ff>b.ff;
}

ll dx[]={-1,0,1,0};
ll dy[]={0,-1,0,1};

void solve(){
    ll n,m;
    cin>>n>>m;
    vector<pair<ll,ll>> vp;
    vector<vector<char>> v(n,vector<char>());
    Input(v,n,m);
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(v[i][j]=='#')vp.pb({i,j});
        }
    }
    vector<vector<ll>> vis(n,vector<ll> (m,0));
    vector<ll> count(n*m+1,0);
    ll c=1;
    for(auto it:vp){
        queue<pair<pair<ll,ll>,ll>> q;
        if(vis[it.ff][it.ss]==0){
            q.push({{it.ff,it.ss},c});
            while(q.size()){
                auto itt=q.front();
                q.pop();
                count[itt.ss]++;
                vis[itt.ff.ff][itt.ff.ss]=itt.ss;
                for(ll k=0;k<4;k++){
                    ll x=itt.ff.ff+dx[k];
                    ll y=itt.ff.ss+dy[k];
                    if(x>=0 && x<n && y>=0 && y<m && vis[x][y]==0 && v[x][y]=='#'){
                        q.push({{x,y},itt.ss});
                        vis[x][y]=itt.ss;
                    }
                }
            }
            c++;
        }
    }
    // display(vis);
    // display(count);
    ll ans=0;
    for(ll i=0;i<n;i++){
        set<ll> s;
        ll ck=0;
        for(ll j=0;j<m;j++){
            if(vis[i][j])s.insert(vis[i][j]);
            else ck++;
            if(i)s.insert(vis[i-1][j]);
            if(i<n-1)s.insert(vis[i+1][j]);
        }
        ll temp=0;
        for(auto it:s){
            temp+=count[it];
        }
        temp+=ck;
        ans=max(ans,temp);
    }
   // cout<<ans<<endl;
    for(ll j=0;j<m;j++){
        set<ll> s;
        ll ck=0;
        for(ll i=0;i<n;i++){
            if(vis[i][j])s.insert(vis[i][j]);
            else ck++;
            if(j)s.insert(vis[i][j-1]);
            if(j<m-1)s.insert(vis[i][j+1]);
        }
        ll temp=0;
        for(auto it:s){
            temp+=count[it];
        }
        temp+=ck;
        ans=max(ans,temp);
    }
    cout<<ans<<endl;
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