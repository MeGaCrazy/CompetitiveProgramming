/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Mar 10 05:35:06 2018
*   @Idea :   as in editorial ..
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
      int n,m;
      scanf("%d %d",&n,&m);
      bool f=1;
      int pos=0;
      int type,p;
      for(int i=0;i<m;i++){
         scanf("%d %d",&type,&p);
         if(type==1){
            pos=(pos+p)%n;
         }else{
           pos=(p-pos+n)%n;
           f=!f;
         }
      }
      if(f){
         printf("1 %d",(n-pos)%n);
      }else{
        printf("2 %d",pos);
      }
       



}