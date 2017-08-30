/*
*      Idea : The Test not Really Clear But All he need is 
*             For each point if we make it like a Turning Point in other world(Form increasing to Decreasing or Vica versa) 
*             dp[][0..1] 0 // for increasing interval // 1 decreasing interval 
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=(int)1e5+7;
int dp[N][2];
int arr[N];




int main(){
    int a,b;
    scanf("%d %d",&a,&b);
    int n= (b-a)+1;
    for(int i=0;i<n;i++){
         scanf("%d",arr+i);
         dp[i][0]=dp[i][1]=1;
         if(!i)continue;
         dp[i][0]=dp[i-1][0];
         if(arr[i]>arr[i-1]){
            dp[i][0]++;
         }
         dp[i][1]=dp[i-1][1];
         if(arr[i]<arr[i-1]){
           dp[i][1]++;
         }
         dp[i][1]=min(dp[i][1],dp[i-1][0]+1);
         dp[i][0]=min(dp[i][0],dp[i-1][1]+1);
    }
    printf("%d\n",min(dp[n-1][1],dp[n-1][0]));
}