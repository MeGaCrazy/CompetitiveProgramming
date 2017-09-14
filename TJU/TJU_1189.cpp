/*
*  
*
*
*/
#include <bits/stdc++.h>
using namespace std;
int n,m;
const int N=1234567;
int mp[N],dp[(1<<14)],c[15];
bool adj[15][15];
int Count(int mask){
      int cnt=0;
     for(int i=1;i<=n;i++){
           if((mask&(1<<i)))cnt++;
      }
     return cnt;
}

int solve(int mask){
      int &ret=dp[mask];
      if(ret!=-1){
           return ret;
      }
      ret=0;
      int cnt=Count(mask);
      int arr[3]={};
       int j=0;
      for(int i=1;i<=n;i++){
          if((mask&(1<<i)))arr[j++]=i;
      }
      if(cnt>3)return ret=0;
      else if(cnt==3){
         if(adj[arr[0]][arr[1]]&&adj[arr[0]][arr[2]]&&adj[arr[1]][arr[2]]){
            for(int i=0;i<=2;i++){
               int sum=0;
               for(int j=0;j<=2;j++){
                  for(int k=0;k<=2;k++){
                     if(i!=j&&j!=k&&i!=k){
                       sum=(c[arr[i]]*c[arr[j]]+c[arr[j]]*c[arr[k]]+c[arr[k]]*c[arr[i]]);
                       sum+=(c[arr[i]]*c[arr[j]]*c[arr[k]])+(c[arr[i]]+c[arr[j]]+c[arr[k]]);
                       cerr<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<" "<< sum <<endl;
                       mp[sum]++;
                       ret=max(ret,sum);
                     }
                  }
               }
            }
            cerr<<" ret "<<ret<<endl;
            return ret;
         }else{
           return ret=0;
         }
      }
      for(int i=1;i<=n;i++){
        if(cnt==0){
           ret=max(ret,solve(mask|(1<<i)));
        }else if((mask&(1<<i))==0){
           for(int k=0;k<j;k++){
             if(adj[arr[k]][i]){
               ret=max(ret,solve((mask|(1<<i))));
             }
           }
        }
    }
    return ret;
}
int main(){
   int t;
   scanf("%d",&t);
   while(t--){
      scanf("%d %d",&n,&m);
      for(int i=1;i<=n;i++){
         scanf("%d",c+i);
      }
      for(int i=0;i<m;i++){
         int a,b;
         scanf("%d %d",&a,&b);
         adj[a][b]=1;
         adj[b][a]=1;      
      }
      memset(mp,0,sizeof(mp));
      memset(dp,-1,sizeof(dp));
      int a=solve(0);
      cerr<<a<<endl;
      if(a==0){
       puts("0 0");
      }else{
        printf("%d %d\n",a,(mp[a]/2));
      }
   }
}