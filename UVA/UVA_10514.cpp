/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Feb 28 14:51:22 2018
*   @Idea :     Get the Shortest Distance between point x in polgoyn 1 and Segments in polygon 2 and Make Floyd 
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
const double EPS=1e-5;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point other){
      return point(x-other.x,y-other.y);
  }
  point operator +(point other){
    return point(x+other.x,y+other.y);
  }
  point operator *(double f){
    return point(x*f,y*f);
  }
};
const int N=25;	
vector<point>arr[N];
double cost[N][N];
double length(point v){
  return sqrt((v.x*v.x)+(v.y*v.y));
}
double dot(point &v1,point &v2){
    return v1.x*v2.x+v1.y*v2.y;
}
double getDis(point &a,point &b,point &c){
  double d1,d2;
  point v1=b-a;
  point v2=c-a;
  if((d1=dot(v1,v2))<=0)return length(c-a);
  if((d2=dot(v1,v1))<=d1)return length(c-b);
  double t=d1/d2;
  point ff=(v1*t)+a;
  return length(c-ff);
}
double disToSeg(int idx1,int idx2){
    double ret=1e18;
    for(int i=0;i<(int)arr[idx1].size();i++){
        for(int j=0;j<(int)arr[idx2].size();j++){
          if(!(idx1<2&&i+1==arr[idx1].size())){
             double tt= getDis(arr[idx1][i],arr[idx1][(i+1)%(int)arr[idx1].size()],arr[idx2][j]);
             if( tt < ret -EPS){
               ret=tt;
             }
          }
          if(!(idx2<2&&j+1==arr[idx2].size())){
             double tt= getDis(arr[idx2][j],arr[idx2][(j+1)%(int)arr[idx2].size()],arr[idx1][i]);
             if( tt < ret -EPS){
               ret=tt;
             }
          }
        }
    }
    return ret;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
        int n,r1,r2;
        double x,y;   
        memset(arr,0,sizeof(arr));
        scanf("%d %d %d",&r1,&r2,&n);
        for(int i=0;i<r1;i++){
            scanf("%lf %lf",&x,&y);
            arr[0].push_back(point(x,y));
        }
        for(int i=0;i<r2;i++){
           scanf("%lf %lf",&x,&y);
           arr[1].push_back(point(x,y));
        }
        n+=2;
        for(int i=2;i<n;i++){
           int sz;
           scanf("%d",&sz);
           for(int j=0;j<sz;j++){
               scanf("%lf %lf",&x,&y);
               arr[i].push_back(point(x,y));
           }
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                cost[i][j]=cost[j][i]=disToSeg(i,j);
               if(i==j)cost[i][j]=0;
               cost[i][j]=disToSeg(i,j);
            }
        }
        for(int k=0;k<n;k++){
           for(int i=0;i<n;i++){
              for(int j=0;j<n;j++){
                 if(i==j)continue;
                 if(cost[i][k]+cost[k][j] < cost[i][j]-EPS){
                    cost[i][j]=cost[i][k]+cost[k][j];
                 }
              }
           }
        }
        printf("%.3f\n",cost[0][1]);
     }
}