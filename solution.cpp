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

int mod=1e9+7;
long long fun(vector<vector<long long>>& dp,vector<int>& v1,vector<int>& v2,map<int,int> mp[],int ck,int ind,int n,int m){
    if(ind>=n)return 0;
    if(dp[ind][ck]!=-1)return dp[ind][ck];
    long long sum=0;
    if(mp[1].count(v1[ind]) && mp[0].count(v1[ind])){
        sum+=max((v1[ind]+fun(dp,v1,v2,mp,ck,ind+1,n,m)),(v1[ind]+fun(dp,v2,v1,mp,ck^1,mp[ck^1][v1[ind]]+1,m,n)));
    }else sum+=(v1[ind]+fun(dp,v1,v2,mp,ck,ind+1,n,m));
    return dp[ind][ck]=sum;
}

    int TreasureHunt(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mp[2];
        int n=nums1.size();
        int m=nums2.size();
        for(int i=0;i<n;i++){
            mp[0][nums1[i]]=i;
        }
        for(int i=0;i<m;i++){
            mp[1][nums2[i]]=i;
        }
        vector<vector<long long>> dp1(max(n,m),vector<long long>(2,-1)),dp2(max(n,m),vector<long long>(2,-1));
         long long ans=max(fun(dp1,nums1,nums2,mp,0,0,n,m),fun(dp2,nums2,nums1,mp,1,0,m,n));
         return (ans%mod);
    }

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);


  // #ifndef ONLINE_JUDGE
  //    freopen("input.txt","r",stdin);
  //    freopen("output.txt","w",stdout);  
  //     #endif
       
//   ll t;
//   cin>>t;
    //for(ll Z=0;Z<t;Z++)
    {
        //cout<<"Case #"<<Z+1<<": ";
        vector<int> nums1 = {1,3,5,7,9}, nums2 = {3,5,100};
      cout<<TreasureHunt(nums1,nums2);
    }
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/