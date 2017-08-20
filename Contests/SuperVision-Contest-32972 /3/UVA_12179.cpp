/*
*     Idea:
*          to make the cost with minimum cost mean have the big probability the closer is the road the big is the probablility can meet
*          we can use APSP (floyd) coz the input not very large
*          then make a probability all he will give us the the towns and the money he have 
*          then the states of dp is (Length of Path) (cost)
*          for every state in dp 
*                 in len 1 i can pay cost from 0 to maxcost
*                             must be within (R) :)
*          then easly we can calculate the probabiltiy for the dp[len][1..themoney_he_have] then that is the answer :)
*/

#include <bits/stdc++.h>
using namespace std;
const int N=150,maxcost=10005;
char s[N];
int arr[N][N];
double dp[N][maxcost];
int main(){
    int t,Case=1;
    scanf("%d",&t);
    while(t--){
       int n,r;
       scanf("%d %d",&n,&r);
       for(int i=0;i<n;i++){
         scanf("%s",&s);
         for(int j=0;j<n;j++){
           arr[i][j]=s[j]=='Y'?1:(int)1e9;
         }
       }
       // floyd
       for(int k=0;k<n;k++){
          for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
              arr[i][j]=min(arr[i][j],arr[i][k]+arr[k][j]);
             }
          }
       }
    
    memset(dp,0,sizeof(dp));
    dp[0][0]=1;
    for(int i=0;i<=n;i++){
       for(int j=0;j<maxcost;j++){
          if(dp[i][j]==0)continue;
           for(int k=1;k<=r&&(j+k)<maxcost;k++){
             dp[i+1][j+k]+=dp[i][j]/r;
             //cerr<<dp[i+1][j+k]<<endl;
           }
       }
    }
    printf("Case %d\n",Case++);
    int q;
    scanf("%d",&q);
    int a,b,c;
    while(q--){
       scanf("%d %d %d",&a,&b,&c);
       a--,b--;
       int dis=arr[a][b];
//       cerr<<dis<<" a "<<a<<" "<<" b "<<b<<endl;
       double ans=0;
       if(dis!=(int)1e9){
          for(int i=0;i<=c;i++){
             ans+=dp[dis][i];
          }
       }
       	printf("%.6lf\n",ans);
    }
      puts("");
  }

}

