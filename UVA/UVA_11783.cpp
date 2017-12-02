/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Dec 02 21:51:02 2017
*   @Idea :   Just Check Intersect for every point with others if =0 make it equal 4 and at last divide by 2 
*
*
*
*
*
*  Happy Solving :)
**/

struct point{
   int x,y;
};
struct seg{
  point s,e;
};
const int N=1005;
seg a[N];
int cnt[N];
long long Cross(point o, point a, point b) {
    return (long long)(a.x-o.x)*(b.y-o.y)-(a.y-o.y)*(b.x-o.x);
}
bool Inter(int i,int j){
   if(Cross(a[i].s,a[i].e,a[j].s)*Cross(a[i].s,a[i].e,a[j].e) <=0 &&
            Cross(a[i].e,a[i].s,a[j].s)*Cross(a[i].e,a[i].s,a[j].e) <=0 &&
            Cross(a[j].s,a[j].e,a[i].s)*Cross(a[j].s,a[j].e,a[i].e) <=0 &&
            Cross(a[j].e,a[j].s,a[i].s)*Cross(a[j].e,a[j].s,a[i].e) <=0
            )return 1;

    return 0;

}
#include <bits/stdc++.h>
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
      int n;
      while(scanf("%d",&n),n){
            int ans=0;
           memset(cnt,0,sizeof(cnt));
           for(int i=0;i<n;i++){
             scanf("%d %d %d %d",&a[i].s.x,&a[i].s.y,&a[i].e.x,&a[i].e.y);
           }
           for(int i=0;i<n;i++){ 
               for(int j=i+1;j<n;j++){
                 if(i==j)continue;
                 if(Inter(i,j)){
                    cnt[i]++;
                    cnt[j]++; 
                 }
               }
           }
           for(int i=0;i<n;i++){
             ans+=(cnt[i]?cnt[i] : 4);
           }
           printf("%d\n",(ans>>1));
      }

}