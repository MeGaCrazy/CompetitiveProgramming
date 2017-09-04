/*
*     Idea : make ranges from right to left ... Start From end 
*            and state is [right][left] The Range how we can calculate the Range 
*            our recurrence doing this :
*                                         i(i+1)..........(j-1)j
*                                          |__________________|
*                                           The number of un similar char between i and j  
*                                        Then the state is dp[i][j]=dp[i+1][j-1]+(s[i]!=s[j] That mean need to change this to make i,j palandormie :))
*
*          Happy Solving :)  
*/                                        
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
char s[N];
int dp[N][N];
int k;
int main(){
#ifndef ONLINE_JUDGE
      freopen("in","r",stdin);
#endif
    int t;
    scanf("%d",&t);
    while(t--){
       scanf("%s %d",&s,&k);
       int ans=0;
       int n=strlen(s);
       for(int i=n;i>=1;i--){
         for(int j=i;j<=n;j++){
          dp[i][j]=dp[i+1][j-1]+(s[i-1]!=s[j-1]);
          if(dp[i][j]<=k)ans=max(ans,(j-i+1));
         }
       }
       printf("%d\n",ans);
//       fprintf(stderr,"The Test Run in =%d ms\n",(int)clock());
    }


}
