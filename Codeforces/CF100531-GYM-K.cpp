/*
*    Idea : 1- All u care about what's happen in last kebab cool so u can reduce the state to [prev(0...1)][SecondiHave][SecondDreams]
*           2- initiaily we prev make all state valid = 1
*           3- then try to make k second dream for every state 
*                (a) if i dream and i consume my all avaible second i can take my need from prev one
*                (b) else if i dream 1 time so i add value of dream 2 time in mycurrent time + (T)
*         Happy Solving :)
*       
*/ 
#include <bits/stdc++.h>
using namespace std;
const int N=1005,MOD=(int)1e9+7;
int dp[2][351][251];
int q[N],x[N];
int main(){
  // freopen("kebab.in","r",stdin);
  // freopen("kebab.out","w",stdout);
   int n,t;
   scanf("%d %d",&n,&t);
   for(int i=0;i<n;i++){
      scanf("%d %d",q+i,x+i);
   }
   memset(dp,0,sizeof(dp));
   for(int i=0;i<=350;i++){
      for(int j=0;j<=250;j++){
         dp[0][i][j]=1;
      }
   }
   int cur=1;
   for(int i=n-1;i>=0;i--){
     for(int j=350;j>=0;j--){
        for(int k=q[i]-x[i];k>=0;k--){
           if(j+k >= q[i]){
              dp[cur][j][k]=(dp[cur][j][k]%MOD+dp[!cur][j+k-q[i]][0]%MOD)%MOD;
           }else{
             if(j+1 <=350){
                dp[cur][j][k]=dp[cur][j+1][k];
             }
             dp[cur][j][k]=(dp[cur][j][k]%MOD+dp[cur][j+t][k+1]%MOD)%MOD;
           }
        }
     }
     cur=!cur;
      for(int k=0;k<=350;k++){
         for(int j=0;j<=250;j++){
            dp[cur][k][j]=0;
         }
      }
   }
   printf("%d\n",dp[!cur][0][0]);
}




/*    Passed But the Memory Very Very Large i was Luckey Just 2 kb and the code Get Memory limit
#include <bits/stdc++.h>
using namespace std;
const int N=1001;
int X[N],Q[N];
int dp[N][251][251];
const int MOD=(int)1e9+7;
int n,t;
int solve(int idx,int q,int x){
    if(idx==n)return 1;
    if(q < 0) return solve(idx+1,Q[idx+1]+q,X[idx+1]+q);
    x=max(0,x);
    if( x > q)return 0;
    int &ret=dp[idx][q][x];
    if(ret!=-1)return ret;
    
    ret=0;
     // dream 
     if(q > x){
       if(q==0) ret=(ret+solve(idx+1,Q[idx+1]-(t),X[idx+1]-(t)))%MOD;
        else    ret=(ret+solve(idx,q-t-1,x-t))%MOD;
    }
   //undream
   if(q==0) ret=(ret+solve(idx+1,Q[idx+1],X[idx+1]))%MOD;
   else  ret=(ret+solve(idx,q-1,x-1))%MOD;

    return ret=(ret)%MOD;
}
int main(){
        
     freopen("kebab.in","r",stdin);
     freopen("kebab.out","w",stdout);
     memset(dp,-1,sizeof(dp));
     scanf("%d %d",&n,&t);
     for(int i=0;i<n;i++){
        scanf("%d %d",&Q[i],&X[i]);
     }
     printf("%d\n",solve(0,Q[0],X[0]));

}
*/
