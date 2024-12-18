//Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
#define ff first
#define ss second
#define yes cout<<"Yes"<<endl
#define no cout<<"No"<<endl
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

//https://www.geeksforgeeks.org/minimum-substring-reversals-required-to-make-given-binary-string-alternating/
int minimumReverse(string& s, ll n)
{
    // Store count of consecutive pairs
    int k = 0 , l = 0 ;
 
    // Stores the count of 1s and 0s
    int sum1 = 0, sum0 = 0;
 
    // Traverse through the string
    for (int i = 1; i < n; i++) {
 
        if (s[i] == '1')
 
            // Increment 1s count
            sum1++;
        else
 
            // Increment 0s count
            sum0++;
 
        // Increment K if consecutive
        // same elements are found
        if (s[i] == s[i - 1]&& s[i] == '0')
            k++;
      else if( s[i] == s[i - 1]&& s[i] == '1')
        l++;
    }
   
    // Increment 1s count
    if(s[0]=='1')     
       sum1++;
    else  // Increment 0s count
       sum0++;
 
    // Check if it is possible or not
    if (abs(sum1 - sum0) > 1)
        return -1;
 
    // Otherwise, print the number
    // of required operations
    return max(k , l );
}

void solve(){
    ll n;
    cin>>n;
    string s;
    cin>>s;
    ll ans=minimumReverse(s,n) ;
    // cout<<ans<<" ";
    if(ans>1 || ans==-1)no;
    else yes;
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