//Yash_Jaiswal
#include <bits/stdc++.h>
using namespace std;
using namespace std::chrono;

vector<vector<int>> maxpooling1(vector<vector<int>>& image,int window_size){
  int image_size=image.size();
  vector<vector<int>> window(image_size,vector<int>(image_size,0));

  for(int i=0;i<=image_size-window_size;i++){
    for(int j=0;j<=image_size-window_size;j++){
      int mx_val=INT_MIN;

      // We iterate for each window
      for(int range_x=0;range_x<window_size;range_x++){
        for(int range_y=0;range_y<window_size;range_y++){
          mx_val=max(mx_val,image[i+range_x][j+range_y]);
        }
      }
      
      // Storing the max value
      window[i][j]=mx_val;
    }
  }
  return window;
}

vector<vector<int>> maxpooling2(vector<vector<int>>& image, int window_size) {
  int image_size = image.size();
  vector<vector<int>> window(image_size, vector<int>(image_size, 0));
  vector<vector<int>> max_row(image_size, vector<int>(image_size - window_size + 1));

  // Precompute max values for each row in the window size
  for (int i = 0; i < image_size; ++i) {
      for (int j = 0; j <= image_size - window_size; ++j) {
          int mx_val = INT_MIN;

          for (int range_y = 0; range_y < window_size; ++range_y) {
              mx_val = max(mx_val, image[i][j + range_y]);
          }
          max_row[i][j] = mx_val;
      }
  }
//   for(auto it:max_row){
//     for(auto it1:it){
//      cout<<it1<<" ";
//     }
//     cout<<endl;
// }
// cout<<endl<<endl;
  // 3 4 5
  // 4 5 6
  // 5 6 7
 //  3 4 5
 //  6 7 8
 // max_row[5][5-3+1]=max_row[5][3]

  // Use the precomputed row max values to compute the max values in the window
  for (int i = 0; i <= image_size - window_size; ++i) {
      for (int j = 0; j <= image_size - window_size; ++j) {
          int mx_val = INT_MIN;
          for (int range_x = 0; range_x < window_size; ++range_x) {
              mx_val = max(mx_val, max_row[i + range_x][j]);
          }
          window[i][j] = mx_val;
      }
  }
 // 5 6 7
 // 5 6 7
 // 6 7 8
  return window;
}

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int m=15;
  int k=10;
  std::chrono::time_point<std::chrono::system_clock> start, end,start1,end1;
  vector<vector<int>> image={
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15},
    {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}
  };
  // 7 8 9 10 11 12 
  start = std::chrono::system_clock::now();
     cout<<"Apprroach 1:"<<endl;
  for(int i=0;i<10000;i++){
  vector<vector<int>> ans1=maxpooling1(image,k); // Time_complexicity -> O( m^2 * k^2 )//  Time_complexicity -> O( m^2 * k)
  // for(int i=0;i<m;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<ans1[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
  //cout<<endl;
  }
  // 1 2 3 4 5 6 7 8 9 10
  // 5 1 2 6 7 3 4 8 9 10

int v1[10]-> position // ind val
int ans[10]->

for(int i=0;i<10;i++){
  int val=v1[i];
  ans[val]=i;
}
  // 1 2 3 4 5 6 7 8 9 10
 //  2 3 6 7 1 4 5 8 9 10

 // pos-> 5.6 2.1 3.4 1.2 6.8 5.7 3.5 1.1
 // 
// O(log(size pushed))
  end = std::chrono::system_clock::now();
  double ans1,ans2;
  ans1=std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  cout<<ans1<<endl;

  start1 = std::chrono::system_clock::now();
  cout<<"Apprroach 2:"<<endl;
  for(int i=0;i<10000;i++){
  vector<vector<int>> ans2=maxpooling2(image,k);
  // for(int i=0;i<m;i++){
  //   for(int j=0;j<m;j++){
  //     cout<<ans2[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }
   
  }
  end1 = std::chrono::system_clock::now();
  ans2=(std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count());
  cout<<ans2<<endl;
  }
/*
Hey, you look strong..!!
Wanna fight..?
      ~ Goku
*/