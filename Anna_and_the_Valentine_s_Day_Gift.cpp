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
template<typename T, typename U>
void displayPriorityQueue(priority_queue<pair<T, U>> pq) {
    while (!pq.empty()) {
        cout << "(" << pq.top().first << ", " << pq.top().second << ") ";
        pq.pop();
    }
    cout << endl;
}

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
      ll n,m;
      cin>>n>>m;
      vector<ll> v;
      Input(v,n);
      priority_queue<pair<ll,ll>> p1;
      {;
        for(ll j=0;j<n;j++){
          for(ll i=0;i<11;i++){
            ll d=Pow(10,i);
            if(v[j]%d!=0){
                ll f=0;
                ll t=v[j];
                while(t>0){
                    f++;
                    t/=10;
                }
                p1.push({i-1,f});
                break;
            }
          }
        }
      }
     // displayPriorityQueue(p1);
        ll d=0;
        while(true){
            if(d==0){
                auto it =p1.top();
                p1.pop();
                p1.push({0,abs(it.ss-it.ff)});
              //  cout<<d<<"--"<<it.ff<<" "<<it.ss<<Endl;
              if(p1.size()==1)break;
                d^=1;
            }else{
              if(p1.size()==1)break;
                auto it1=p1.top();
                p1.pop();
               // cout<<d<<"--"<<it1.ff<<" "<<it1.ss<<Endl;
                auto it2=p1.top();
                p1.pop();
               // cout<<d<<"--"<<it2.ff<<" "<<it2.ss<<Endl;
                p1.push({min(it1.ff,it2.ff),it1.ss+it2.ss});
                auto it =p1.top();
               // cout<<d<<"--"<<it.ff<<" "<<it.ss<<Endl;
                d^=1;
            }
          //  displayPriorityQueue(p1);
      }
      if(p1.top().ss>=m+1)cout<<"Sasha"<<endl;
        else cout<<"Anna"<<Endl;
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/