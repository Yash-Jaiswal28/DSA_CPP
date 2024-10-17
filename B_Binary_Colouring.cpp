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
    ll ck=log2(n);
    if(Pow(2,ck)==n){
        vector<ll> v(ck+1);
        v[ck]=1;
        cout<<v.size()<<endl;
        display(v);
    }else{
        // vector<ll> v(ck+1),v1(ck+2),v2(ck+4);
        // v[ck]=1;
        // v1[ck+1]=1;
        // v2[ck+3]=1;
        // ll e=pow(2,ck+1)-n;
        // ll d=pow(2,ck)-n;
        // ll f=pow(2,ck+3)-n;
        // for(ll i=ck-2;i>=0;i--){
        //     if(d<0){
        //         d+=Pow(2,i);
        //         v[i]=1;
        //         i--;
        //     }else
        //     if(d>0){
        //         v[i]=-1;
        //        // i--;
        //         d-=Pow(2,i);
        //         i--;
        //         //cout<<d<<endl;
        //     }
        // }
        // for(ll i=ck-1;i>=0;i--){
        //     if(e<0){
        //         e+=Pow(2,i);
        //         v1[i]=1;
        //         i--;
        //     }else
        //     if(e>0){
        //         v1[i]=-1;
        //        // i--;
        //         e-=pow(2,i);
        //        i--;
        //        // cout<<e<<endl;
        //     }
        // }
        // for(ll i=ck+1;i>=0;i--){
        //     if(f<0){
        //         f+=Pow(2,i);
        //         v2[i]=1;
        //         i--;
        //     }else
        //     if(f>0){
        //         v2[i]=-1;
        //        // i--;
        //         f-=Pow(2,i);
        //        i--;
        //        // cout<<e<<endl;
        //     }
        // }
       // cout<<"check "<<d<<" "<<e<<" "<<f<<endl;
        // if(e==0){
        //   //  cout<<"ck"<<Endl;
        //     cout<<v1.size()<<endl;
        //     display(v1);
        //     return;
        // }else if(f==0){
        //     cout<<v2.size()<<endl;
        //     display(v2);
        //     return;
        // }
        // cout<<v.size()<<endl;
        // display(v);
        for(ll i=0;i+ck<32;i++){
            vector<ll> t(ck+i);
            t[ck+i-1]=1;
            ll x=pow(2,ck+i-1)-n;
            for(ll j=ck+i-3;j>=0;j--){
                if(x>0){
                    t[j]=-1;
                    x-=pow(2,j);
                    j--;
                }else if(x<0){
                    t[j]=1;
                    x+=pow(2,j);
                    j--;
                }
            }
            if(x==0){
                cout<<t.size()<<endl;
                display(t);
                return;
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
      solve();
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/