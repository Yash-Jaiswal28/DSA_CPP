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
    ll n;
    cin>>n;
    vector<ll> v;
    Input(v,n);
    set<ll> s;
    s.insert(0);
    ll ind=-1;
    for(ll i=0;i<n;i++){
        if(v[i]!=-1 && v[i]!=1){
            ind=i;
            break;
        }
    }
    ll tempmax=0,tempmin=0;
    if(ind!=-1){
    ll l1=0,r1=0;
    for(ll i=0;i<ind;i++){
        tempmax=max(v[i], tempmax+v[i]);
        tempmin=min(v[i],tempmin+v[i]);
        l1=min(l1,tempmin);
        r1=max(r1,tempmax);
    }
    ll tempmax1=0,tempmin1=0;
    ll l2=0,r2=0;
    for(ll i=ind+1;i<n;i++){
        tempmax1=max(v[i],tempmax1+v[i]);
        tempmin1=min(v[i], tempmin1+v[i]);
        l2=min(l2,tempmin1);
        r2=max(r2,tempmax1);
    }
    for(ll i=l1;i<=r1;i++){
        s.insert(i);
    }
    for(ll i=l2;i<=r2;i++){
        s.insert(i);
    }
    ll leftmin=0,leftmax=0,rightmin=0,rightmax=0;
    ll num1=0,num2=0;

    for(ll i=ind-1;i>=0;i--){
        num1+=v[i];
        leftmin=min(leftmin,num1);
        leftmax=max(leftmax,num1);
    }

    for(ll i=ind+1;i<n;i++){
        num2+=v[i];
        rightmin=min(rightmin,num2);
        rightmax=max(rightmax,num2);
    } 
    ll l=v[ind]+rightmin+leftmin;
    ll r=v[ind]+rightmax+leftmax;

    for(ll i=l;i<=r;i++){
        s.insert(i);
    }
    // cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<" "<<leftmin<<" "<<leftmax<<" "<<rightmin<<" "<<rightmax<<endl;
    cout<<s.size()<<endl;
    for(auto it:s)cout<<it<<" ";
    cout<<endl;
    }else{
        ll l1=0,r1=0;
    for(ll i=0;i<n;i++){
        tempmax=max(v[i], tempmax+v[i]);
        tempmin=min(v[i],tempmin+v[i]);
        l1=min(l1,tempmin);
        r1=max(r1,tempmax);
    }
    for(ll i=l1;i<=r1;i++){
        s.insert(i);
    }
    // cout<<l1<<" "<<r1<<endl;
    cout<<s.size()<<endl;
    for(auto it:s)cout<<it<<" ";
    cout<<Endl;
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