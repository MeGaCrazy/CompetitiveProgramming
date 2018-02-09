/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 09 11:04:29 2018
*   @Idea :    Just using atan2 to calculate the angle and sort according to angle -> dis -> id
*    Corner Case :  take care the angle can <0 then add +360 :)
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}

};
const int N=1005;
const double EPS=1e-5;
point arr[N];
int dcmp(double x,double y){
    return fabs(x-y)<=EPS?0:x>y?1:-1;
}
bool cmp(pair<double,pair<double,int> >&a,pair<double,pair<double,int> >&b){
     return (dcmp(a.first,b.first)==-1||((dcmp(a.first,b.first)==0&&dcmp(a.second.first,b.second.first)==-1))||
         (dcmp(a.first,b.first)==0&&dcmp(a.second.first,b.second.first)==-1&&dcmp(a.second.first,b.second.second)==-1)
     );
}
double length(double x,double y){
    return sqrt((x*x)+(y*y));
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    vector<pair<double,pair<double,int> > >v;
    for(int i=0;i<n;i++){
        scanf("%lf %lf",&arr[i].x,&arr[i].y);
        double angel=atan2(arr[i].y,arr[i].x)*180/acos(-1);
        if(dcmp(angel,0)==-1)angel+=360.0;
        v.push_back(make_pair(angel,make_pair(length(arr[i].x,arr[i].y),i)));
    }
    sort(v.begin(),v.end(),cmp);
    for(int i=0;i<(int)v.size();i++){
        int idx=v[i].second.second;
        printf("%.0f %.0f\n",arr[idx].x,arr[idx].y);
    }
}