/**
*  Idea : First Check one of point in one seg on another and then Check cross product if < 0 then it can be Intersect :) 
*      Corner Case : u must Check Cross product for all possible cases :) 
*
**/


#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
};
struct seg{
  point s,e;
};
const int N=1005;
seg a[N];
double in(double s,double e,double x){
 return x >=s && x <= e;
}
bool PointOn(seg &S,point & P){
    double minx,maxx,miny,maxy;
    minx=min(S.s.x,S.e.x);
    maxx=max(S.s.x,S.e.x);
    miny=min(S.s.y,S.e.y);
    maxy=max(S.s.y,S.e.y);
    if(in(minx,maxx,P.x) !=0  && in(miny,maxy,P.y)!=0){
       return ((S.s.x - S.e.x)*(P.y - S.s.y) == (S.s.y - S.e.y) * (P.x - S.s.x));
    }
     return 0;
}
double Cross(point &o,point &a,point &b){
     return (a.x - o.x) * (b.y - o.y) - ( b.x - o.x ) * (a.y - o.y);

}
bool Intersect(int i,int j){
         if(PointOn(a[i],a[j].s)||PointOn(a[i],a[j].e)||PointOn(a[j],a[i].s)||PointOn(a[j],a[i].e)){
         //   cerr<<i <<"  "<<j<<endl;
             return 1;
         }
         if(Cross(a[i].s,a[i].e,a[j].s)*Cross(a[i].s,a[i].e,a[j].e) <0 &&
            Cross(a[i].e,a[i].s,a[j].s)*Cross(a[i].e,a[i].s,a[j].e) <0 &&
            Cross(a[j].s,a[j].e,a[i].s)*Cross(a[j].s,a[j].e,a[i].e) <0 &&
            Cross(a[j].e,a[j].s,a[i].s)*Cross(a[j].e,a[j].s,a[i].e) <0
            )return 1;

            return 0;
}
bool iso[N];                                                                 
int main(){
#ifndef ONLINE_JUDGE
         freopen("in","r",stdin);
         freopen("out","w",stdout);
#endif
        int t;
        scanf("%d",&t);
        while(t--){
           int n;
           memset(iso,0,sizeof(iso));
           scanf("%d",&n);
           for(int i=0;i<n;i++){
               scanf("%lf %lf %lf %lf",&a[i].s.x,&a[i].s.y,&a[i].e.x,&a[i].e.y);
           }
           int ans=0;
           for(int i=0;i<n;i++){
               if(!iso[i]){
                  for(int j=0;j<n;j++){
                     if(i==j)continue;
                     if(Intersect(i,j)){
                       iso[i]=iso[j]=1;
                     }
                  }
               }
               if(!iso[i])ans++;
           }
           printf("%d\n",ans);
        }
}