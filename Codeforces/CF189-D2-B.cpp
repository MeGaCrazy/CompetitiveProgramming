/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Jan 23 04:31:56 2018
*   @Idea :
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
//   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
    int w,h;
    scanf("%d %d",&w,&h);
    long long ans=0;
    for(int i=2;i<=w;i+=2){
        for(int j=2;j<=h;j+=2){
            int w1=(w-i+1);
            int h1=(h-j+1);
            ans+=(long long)w1*h1;
        }
    }
    printf("%lld",ans);




}