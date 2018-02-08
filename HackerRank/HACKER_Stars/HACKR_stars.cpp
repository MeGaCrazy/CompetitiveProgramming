/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 07 14:56:16 2018                                 x     x
*   @Idea :    For Each Point Make all his all possible line for example    O      that mean we can make line above him or right to him or left ....
*                                                                        x     x               
*              So Just Generate all and then for each line check who  is right to him and who is left..
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  int w;
  point(double x=0.0,double y=0.0,int w=0):x(x),y(y),w(w){}
  point operator -(point &other){
     return point(x-other.x,y-other.y);
  }
};
const int N=105;
int n;
point arr[N];
const double EPS=1e-5;
double cross(point &v1,point &v2){
   return v1.x*v2.y-v1.y*v2.x; 
}
int main(){
#ifndef ONLINE_JUDGE
  // freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
     vector<pair<double,double> >v;
     scanf("%d",&n);
     for(int i=0;i<n;i++){
          scanf("%lf %lf %d",&arr[i].x,&arr[i].y,&arr[i].w);
     //     cerr<<arr[i].x+1<<" "<<arr[i].y<<" "<<arr[i].w<<endl;
          for(int k=-1;k<=1;k+=2){
             for(int j=-1;j<=1;j+=2){
               v.push_back(make_pair(arr[i].x+k*EPS,arr[i].y+j*EPS));
             }
          }
     }
     int ans=-1;
     for(int i=0;i<(int)v.size();i++){
         for(int j=i+1;j<(int)v.size();j++){
             point a=point(v[i].first,v[i].second);
             point b=point(v[j].first,v[j].second);
             int l=0,r=0;
             point v1=b-a;
             //cerr<<v1.x<<" "<<v1.y<<endl;
             for(int k=0;k<n;k++){
                  point v2=arr[k]-a;
               //   cerr<<v2.x<<" "<<v2.y<<endl;
                  if(cross(v1,v2) >=EPS){
                    r+=arr[k].w;
                  }else l+=arr[k].w;
             }
             
             ans=max(ans,min(l,r));
         }
     }
     printf("%d",ans);

}