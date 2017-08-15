/*
*   Twist using of Segment Tree distrubiton range :) 
*    Just to manage the each node the left nodes get the right nodes to get porability :) 
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=18;
string str[N];
double arr[N][N];
double dp[N*4][N];
void solve(int p,int l,int r){
      if(l==r){
        dp[p][l]=1;
        return;
      }
      int mid=(l+r)>>1;
      int np=p<<1;
      solve(np,l,mid);
      solve(np+1,mid+1,r);
      for(int i=l;i<=mid;i++){
         for(int j=mid+1;j<=r;j++){
            dp[p][i]+=(dp[np][i]*dp[np+1][j]*arr[i][j]);
            dp[p][j]+=(dp[np][i]*dp[np+1][j]*arr[j][i]);
         }
      }
}
int main(){
     for(int i=1;i<=16;i++){
          cin>>str[i];
     }
     for(int i=1;i<=16;i++){
       for(int j=1;j<=16;j++){
          scanf("%lf",&arr[i][j]);
            arr[i][j]/=100.0;
            cerr<<arr[i][j]<<endl;
        }
     }
     solve(1,1,16);
     for(int i=1;i<=16;i++){
       printf("%-10s p=%.2lf%\n",str[i].c_str(),dp[1][i]*100); 
     }


}