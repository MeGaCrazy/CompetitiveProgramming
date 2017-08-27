/*
*       Idea : Sorting x and y then get the distance between every points like dis[1] is distance between point 0 2 and so on
*              then sorting it then to get the Area the it easly Height (y) * distance :) now if u see we duplicate the answer coz the distance for every point 
*              Just divide by 2 to remove it :)
*              Happy Solving :)
*
*
*/
#include <bits/stdc++.h>
using namespace std;
const int N=1005;
double x[N],y[N],dis[N];

int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       int t;
       scanf("%d",&t);
       while(t--){
         int n;
         scanf("%d",&n);
         for(int i=0;i<n;i++){
            scanf("%lf%lf",x+i,y+i);
         }
         sort(x,x+n);
         sort(y,y+n);
         dis[0]=x[1]-x[0];
         dis[n-1]=x[n-1]-x[n-2];
         for(int i=1;i<n-1;i++){
             dis[i]=x[i+1]-x[i-1];
         }
         sort(dis,dis+n);
         double ans=0;
         for(int i=0;i<n;i++){
           ans+=y[i]*dis[i];
         }
         printf("%.1f\n",ans/2.0);
     }

}