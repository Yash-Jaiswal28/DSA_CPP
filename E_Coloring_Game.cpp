#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
#define pb push_back
// typedef long long int int;
 
#define ff first
#define ss second
  
    


   void solve(){
 

    int n,m;
    cin>>n>>m;

    vector<vector<int>> vv(n);
   

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        u--; v--;
        vv[u].pb(v);
        vv[v].pb(u);
        
         
    }

     vector<int> col(n,0);
        col[0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
         
          bool ans=true;
        while(!q.empty()){
          auto it=q.front();
          q.pop();
          int tm=it.ff;
          int nd=it.ss;
          if(tm%2==0) col[nd]=1;
          else col[nd]=2;

          for(auto itt:vv[nd]){
            if(col[itt]==col[nd]) ans=false;
            else
            if(col[itt]==0){
                col[itt]=col[nd]^3;
                q.push({tm+1,itt});
            }
          }
        }
	

     if(!ans) {
        cout<<"Alice"<<endl;
       
       cout<<1<<" "<<2<<endl;
        
       
       for(int i=0;i<n;i++){
        int nd,cl;
        cin>>nd>>cl;
        nd--;
        if(i==n-1) break;
        cout<<1<<" "<<2<<endl;
           
       }
        
       
     }
     else {
        cout<<"Bob"<<endl;
         
        
        set<int> s1,s2;
        for(int i=0;i<n;i++){
            // cout<<i<<" "<<col[i]<<endl;
            if(col[i]==1) s1.insert(i);
            else s2.insert(i);
        }

        for(int i=0;i<n;i++){
            int c1,c2;
            cin>>c1>>c2;
          
         
          if(s1.size()>0 && (c1==1 || c2==1)) {
            cout<<*s1.begin()+1<<" "<<1<<endl;
            s1.erase(s1.begin());
          }
          else if(s2.size()>0 && (c2==2 || c1==2)) {
            cout<<*s2.begin()+1<<" "<<2<<endl;
            s2.erase(s2.begin());
          } 
          else {
            if(s1.size()>0){
                 cout<<*s1.begin()+1<<" "<<3<<endl;
            s1.erase(s1.begin());
            }
            else {
                 cout<<*s2.begin()+1<<" "<<3<<endl;
            s2.erase (s2.begin());
            }
          }
          
        
        }
     } 
    
   
 
     return;
   }
  
  
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     
    
    int t;
    cin>>t;
    while(t--)
    solve();

}

 