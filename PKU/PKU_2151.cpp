/*
*  target : culate the probability that all of the teams solve at least one problem,
*              and at the same time the champion team solves at least N problems
*     sol : Using Bottom-up DP with 3 dimentions (TeamNumber,ProblemNumber,NumOfSucess to solve)..
*           for each team i .. in problem j can be succeed from 0-j Just check if  with to forumla :
*           First if NoSucess to solve k=0 then dp[i][j][k]=dp[i][j-1][k]*(1-SucessRateInProblem)
*           else then there is to choice first it success or not ...
*           dp[i][j][k]=dp[i][j-1][k-1]*(arr[i][j])+(dp[i][j-1][k]*(1-arr[i][j]);
*           Then just get sum of All Posiblities in m(last problem) succes one or two there for each team. do the same for again
*           but get how is less than achieve N success and get the difference.. :) 
*
*
*
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
const int N=1234;
double dp[N][35][35],arr[N][35];



int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif 
       int m,t,n;
       while(scanf("%d %d %d",&m,&t,&n),(m||t||n)){
           for(int i=1;i<=t;i++){
               for(int j=1;j<=m;j++){
                  scanf("%lf",&arr[i][j]);
               }
           }
           memset(dp,0,sizeof(dp));
           for(int i=1;i<=t;i++){
               dp[i][0][0]=1;
               for(int j=1;j<=m;j++){
                  for(int k=0;k<=j;k++){
                    if(k==0){
                       dp[i][j][k]=dp[i][j-1][k]*(1-arr[i][j]);
                    }else{
                       dp[i][j][k]=dp[i][j-1][k-1]*(arr[i][j])+dp[i][j-1][k]*(1-arr[i][j]);
                    }
                 }
             }
          }
          double ans1=1,ans2=1,sum=0;
          for(int i=1;i<=t;i++){
              sum=0;
              for(int j=1;j<=m;j++){
                 sum+=dp[i][m][j];
              }
              ans1*=sum;
          }
          for(int i=1;i<=t;i++){
              sum=0;
              for(int j=1;j<n;j++){
                sum+=dp[i][m][j];
              }
              ans2*=sum;
          }
          ans1-=ans2;
          printf("%0.3lf\n",ans1);
       }
}