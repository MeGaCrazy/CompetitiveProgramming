/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 16 15:04:00 2018
*   @Idea :   Just make bfs to check connect nodes ... the valid state for overlap ones is distance between then < radius1+radius2
*             + u must check that the circle not in another one..     
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const int N=105;
struct circ{
 double x,y,r;
};
circ arr[N];
bool visit[N];
const double EPS=1e-5;
int n;
int dcmp(double x,double y){
  return fabs(x-y)<EPS?0:x>y?1:-1;
}
double dis(double x,double y,double xx,double yy){
   return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
int solve (int st){  
      int ret=0;
      queue<int>q;
      q.push(st);
      visit[st]=1;
      ret=1;
      while(!q.empty()){
         int u=q.front();
         q.pop();
         for(int i=0;i<n;i++){
            if(visit[i])continue;
            double dist=dis(arr[u].x,arr[u].y,arr[i].x,arr[i].y);

            if(dcmp(dist,arr[u].r+arr[i].r)!=-1)continue;
            double rmin=arr[u].r;
            double rmax=arr[u].r;
            if(dcmp(arr[u].r,arr[i].r)==1){
               rmin=arr[i].r;
            }else{	
              rmax=arr[i].r;
            }
            if(dcmp(dist+rmin,rmax)!=1)continue;
            visit[i]=1;
            ret++;
            q.push(i);
          }
      }
      return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     while(scanf("%d",&n)){
        if(n==-1)break;
        for(int i=0;i<n;i++){
           scanf("%lf %lf %lf",&arr[i].x,&arr[i].y,&arr[i].r);
        }
        int ans=min(1,n); 
        memset(visit,0,sizeof(visit));
        for(int i=0;i<n;i++){
           if(!visit[i])ans=max(ans,solve(i));
        }
        printf("The largest component contains %d ring",ans);
        if(ans==1){
          printf(".\n");
        }else printf("s.\n");
     
     }



}