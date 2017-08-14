/*
*   Just to know that in every step in changeing number of every pieces
*   The over all posiblility in this step is rs+rp+ps to get the probablity 
*   You must dp[0][0][1-p] coz he said that he the only One in island  and so on for others :) 
*   He Said he need to know if the posablablity to be a live so u need to multiply by
*   His change to die like rock so (rock with paper to get the posiablity to live ) 
* 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=105;
double dp[N][N][N];
int main(){
        int r,s,p;
        scanf("%d %d %d",&r,&s,&p);
        memset(dp,0,sizeof(dp));
        dp[r][s][p]=1;
        double ans1=0;
        double ans2=0;
        double ans3=0;
        for(int i=r;i>=0;i--){
           for(int j=s;j>=0;j--){
              for(int k=p;k>=0;k--){
                 int all_pos=i*j+j*k+i*k;
                 if(j==0&&k==0)ans1+=dp[i][j][k];
                 if(i==0&&k==0)ans2+=dp[i][j][k];
                 if(i==0&&j==0)ans3+=dp[i][j][k];
                 if(all_pos==0)continue;
                 if(i>0){
                   dp[i-1][j][k]+=(dp[i][j][k]*i*k)/all_pos;
                 }
                 if(j>0){
                   dp[i][j-1][k]+=(dp[i][j][k]*i*j)/all_pos;
                 }
                 if(k>0){
                  dp[i][j][k-1]+=(dp[i][j][k]*j*k)/all_pos;
                 }
              }
           }
        }
        printf("%.12f %.12f %.12f",ans1,ans2,ans3);

}