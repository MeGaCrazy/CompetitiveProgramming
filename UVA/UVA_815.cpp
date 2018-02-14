/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 14 10:56:54 2018
*   @Idea :    Sort all according their height then calculate the current height if > next one then go further 
*              if not stop
*     
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double EPS=1e-5;
int dcmp(double x,double y){
   return fabs(x-y)<EPS?0:x>y?1:-1;
}
const int N=905;
double a[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n,m;
     int r=1;
     while(scanf("%d %d",&n,&m),(n+m)){
         printf("Region %d\n",r++);
         n=n*m;
         for(int i=0;i<n;i++){
             scanf("%lf",&a[i]);
         }
         double v;
         scanf("%lf",&v);
         sort(a,a+n);
         int sum=0;
         for(int i=0;i<n;i++){
            sum+=a[i];
            double h=(v+sum*100)/(100.0*(i+1));
//            cerr<<h<<" "<<a[i]<<" "<<sum<<endl;
            if(dcmp(h,a[i+1])==-1||i+1==n){
              printf("Water level is %.2f meters.\n%.2f percent of the region is under water.\n",h,((i+1.0)/n)*100.0);
              break;
            }
         }
         puts("");
     
     }



}