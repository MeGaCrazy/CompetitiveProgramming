#include <bits/stdc++.h>
using namespace std;



int main(){
     int n;
     while(scanf("%d",&n),n){
         double bestans=-1.0;
         int ret=0;
         for(int i=0;i<n;i++){
           double a,b;
           scanf("%lf %lf",&a,&b);
           if(a<b)swap(a,b);
           double cal=max(min(a/4.0,b),min(a/2.0,b/2.0));
           if(cal>bestans){
             bestans=cal;
             ret=i+1;
           }
         }
         printf("%d\n",ret);
     
     }



}