/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Jun 26 04:02:45 2018
*   @Idea :   U can look at the problem from rows prespective , u can get the area of every adjacent cells by substract there's column numbers  
*             it was cool that u will notice if u subtract their column will get the area between them :) 
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
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int h,w;
     while(scanf("%d %d",&h,&w)==2){
    	    int ans=0;
    	    stack<int>s;
          for(int i=0;i<h;i++){
          	for(int j=0;j<w;j++){
            	char a;
          		scanf(" %c",&a);
          		if(a!='.')s.push(j);
          	}
          }
          while(!s.empty()){
          	 int a=s.top();
          	 s.pop();
          	 int b=s.top();
          	 s.pop();
          	 ans+=abs(a-b);
          }
          printf("%d\n",ans);

     }



}