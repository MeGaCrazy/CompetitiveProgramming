/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Feb 10 09:10:09 2018
*   @Idea :  For Every segment check if intersect with other segment thrown before it  
*            
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
  point operator -(point &other){
       return point(x-other.x,y-other.y);
  }
  inline bool operator ==(point &other){
    	return x==other.x&&y==other.y;
  }
};
struct seg{
  point a,b;
};
const int N=1e5+7;
seg arr[N];
const double EPS=1e-5;
double norm(point &v){
    return sqrt((v.x*v.x)+(v.y*v.y));
}
double cross(point &v1,point &v2){
   return v1.x*v2.y - v1.y*v2.x;
}
int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) >EPS)return 1;
    if(cross(v1,v2) < -EPS)return -1;
    if(v1.x*v2.x <0 || v1.y*v2.y <0)return -1;
    if(norm(v1) < norm(v2) -EPS)return 1;
    return 0;
}
bool Inter(point &a,point &b,point &c,point &d){
  bool f1=(a==b),f2=(c==d);
  if(f1&&f2)return a==c;
  if(f1)return ccw(c,d,a)==0;
  if(f2)return ccw(a,b,d)==0;
  return ccw(a,b,c)*ccw(a,b,d)<=0&&
         ccw(c,d,a)*ccw(c,d,b)<=0;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
    int n;
    while(scanf("%d",&n),n){
        printf("Top sticks:");
        for(int i=0;i<n;i++){
           scanf("%lf %lf %lf %lf",&arr[i].a.x,&arr[i].a.y,&arr[i].b.x,&arr[i].b.y);
        }
        vector<pair<seg,int> >ans;
        for(int i=n-1;i>=0&&ans.size()<1000;i--){
           bool valid=1;
           for(int j=n-1;j>i;j--){
               if(Inter(arr[j].a,arr[j].b,arr[i].a,arr[i].b)==1){
                 valid=0;
                 break;
               }
           }
           if(valid)ans.push_back(make_pair(arr[i],i+1));
        }
        for(int i=ans.size()-1;i>=0;i--){
           int idx=ans[i].second;
           printf(" %d",idx);
           if(i!=0)printf(",");
           else printf(".");
        }
        puts("");
    }
}