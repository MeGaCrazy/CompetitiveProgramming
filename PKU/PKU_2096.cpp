//#include <bits/stdc++.h>
/*
*      Idea : 1- He want to found the he discover all bugs to make him disgusting Okey 
              2- then Our goal to get the probability that we discover all from n to reach we already reach must discover 0 number 
                 Meaning of Zero we discover all to make him (disgusting :) )
                 cool now Came for Beautiful Probability  we can found:     // i for bugs and j for subsystem
                 1- bugs in same category and same type of problem        dp[i][j]
*                2- bugs in differnet category and same type of problem   dp[i][j+1]
*                3- bugs in same category and differet type of problem    dp[i+1][j]
*                4- bugs in different category and different type of problem  dp[j+1][j+1]
*                now what is probablility to fonud bugs in system one system of S numbers is = 1/s same for n = 1/n;
*                (numberOfBug*NumberOfSystem = that i now can discover )/(allNumber Of Bugs (n) *allNumber Of SubSystem(S))
*                Happy Solving :)
*/                                 
#include <iostream>
#include <stdio.h>
using namespace std;
const int N=1005;
double dp[N][N];


int main(){
    int n,s;
    while(scanf("%d %d",&n,&s)==2){
         dp[n][s]=0;
         for(int i=n;i>=0;i--){
            for(int j=s;j>=0;j--){
             if(i==n&&j==s)continue;
             double prob1=(double)(i*j)/(n*s); // dp[i][j]
             double prob2=(double)((n-i)*(j))/(n*s);  // dp[i+1][j]
             double prob3=(double)((i)*(s-j))/(n*s);  // dp[i][j+1]
             double prob4=(double)((n-i)*(s-j))/(n*s);  // dp[i+1][j+1]
             dp[i][j]=(1+prob2*dp[i+1][j]+prob3*dp[i][j+1]+prob4*dp[i+1][j+1])/(1-prob1);
            }
         }
         printf("%.4f\n",dp[0][0]);
    }

}