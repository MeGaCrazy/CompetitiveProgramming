/*
*  Idea : Just save the first One how satisfy the condition and so on for second and other 
*         Now what's the maximum number how satisfy the condition if we have 1 2 2 we need 3 element array
*         if we have number like 500 how element we need to staisfy 500+(501)/2 > 10^5 now what is the max number 500 :)
*         Then make consective range for every One then easly the answer
*         if the First One the difference between [firstOne][lastOfInterval]-[firstOne][firstOfInterval-1] == The First satisfied number then ans++ 
*         Happy Solving :)
*
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e5+7;
int cnt[505],arr[N],dp[505][N];
map<int,int>mp;


int main(){
     int n,m;
     int k=0;
     scanf("%d %d",&n,&m);
     for(int i=1;i<=n;i++){
         scanf("%d",arr+i);
         mp[arr[i]]++;
         if(mp[arr[i]]==arr[i])cnt[++k]=arr[i];
     }
     for(int i=1;i<=k;i++){
         for(int j=1;j<=n;j++){
            dp[i][j]=dp[i][j-1];
            if(arr[j]==cnt[i])dp[i][j]++;
         }
     }
    while(m--){
       int a,b;
       scanf("%d %d",&a,&b);
       int ans=0;
       for(int i=1;i<=k;i++){
         if(dp[i][b]-dp[i][a-1]==cnt[i])ans++;
       }
       printf("%d\n",ans);
    }

} 


/*
#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int dp[N];
int cnt[N];


int main(){
  int n,m;
  scanf("%d %d",&n,&m);
  dp[0]=0;
  for(int i=1,a;i<=n;i++){
    scanf("%d",&a);
    dp[i]+=dp[i-1];
    if(a<=n){
      cnt[a]++;
      if(a==cnt[a])dp[i]++;
    }
  }
  for(int i=0,a,b;i<m;i++){
      scanf("%d %d",&a,&b);
      printf("%d\n",dp[b]-dp[a-1]);
  }
}
*/
