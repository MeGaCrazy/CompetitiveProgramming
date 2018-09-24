/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Sep 24 13:12:03 2018
*   @Idea :   Get the sum of rows sorted in desc order and same case to columns
*             and use dp to get all best from case from i to k ( Calculate the best of pickup rows and columns don't mix them now)
*             after that we must reduce the intersection cells by p so
*             if we choice k column and (i-k) rows the value we need to reduce is (k)*(i-k)*p :) 
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

const int N=1e3+7,M=1e6+7;
int row[N],col[N];
long long dpc[M],dpr[M];

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif

     priority_queue<int>pqc,pqr;
     int n,m,k,p;
     scanf("%d %d %d %d",&n,&m,&k,&p);
     for(int i=0;i<n;i++){
     	for(int j=0;j<m;j++){
     	    int a;
     	    scanf("%d",&a);
     	    row[i]+=a;
     	    col[j]+=a;
     	    if(i==n-1){
     	    	pqc.push(col[j]);
     	    }
     	}
     	pqr.push(row[i]);
     }
  
     for(int i=1;i<=k;i++){
     	dpr[i]=pqr.top()+dpr[i-1];
     	pqr.push(pqr.top()-p*m);
     	pqr.pop();
     	dpc[i]=pqc.top()+dpc[i-1];
     	pqc.push(pqc.top()-p*n);
     	pqc.pop();

     }
     long long ans=-1e18;
     for(int i=0;i<=k;i++){
     	ans=max(ans,1ll*dpr[i]+dpc[k-i] - (1ll*i*(k-i)*p));	
     }
     printf("%lld",ans);



}