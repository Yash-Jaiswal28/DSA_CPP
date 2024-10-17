//Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define Endl '\n'
#define pb push_back
template <class V> void Input(vector<V> &v,ll n){for(ll i=0;i<n;i++){V element;cin>>element;v.pb(element);}}
void solve(){
    ll n,p,k;
    cin>>n>>p>>k;
    vector<ll> v;
    Input(v,n);
    sort(v.begin(),v.end());
    ll c=0;
    for(ll i=0;i<n;i++){
        if(p>=v[i]){
            c++;
            p-=v[i];
        }else{
            break;
        }
    }
    cout<<c<<endl;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

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