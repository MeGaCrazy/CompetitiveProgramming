/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Jun 15 04:28:03 2018
*   @Idea :   The Idea That There's a edge that can be seen from all other edges 
*             Using polycut trick to check all left for each one and try for each edge on remaining edges
*             if remaining edge or more are still seen by all edges then that possible ,otherwise is impossible
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double EPS=1e-7;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
  	return point(x-other.x,y-other.y);
  }
  point operator +(point &other){
  	return point(x+other.x,y+other.y);
  }
  point operator *(double f){
  	return point(x*f,y*f);
  }
};
const int N=105;
point arr[N];


double cross(point v1,point v2){
	return v1.x*v2.y-v1.y*v2.x;
}

int dcmp(double x,double y){
	  return fabs(x-y)<EPS?0:x>y?1:-1;
}
bool  segInter(point &a,point &b,point &c,point &d,point &inter){
     point u=b-a;
     point v=d-c;
     point w=a-c;
     double f=cross(u,v);
     double t1=cross(v,w)/f;
     double t2=cross(u,w)/f;
   //  cerr<<t1<<" "<<t2<<endl;
   if(f==0){
     return 0;
   }
   if(dcmp(t2,0)==-1||dcmp(t2,1)==1)
     return 0;
   inter=u*t1+a;
   return true;
}
vector<point> polycut(vector<point>&pts,point &a,point &b){
       vector<point>left;
       point v1=b-a;
       point inter;
       for(int i=0;i<pts.size();i++){
          int ii=(i+1)%pts.size();
          if(segInter(a,b,pts[i],pts[ii],inter)){
          	 left.push_back(inter); 
          }
          if(cross(v1,pts[i]-a)<=0)left.push_back(pts[i]);

      }
      return left;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n;
    int F=0;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
          scanf("%lf %lf",&arr[i].x,&arr[i].y);
        }
        vector<point>pts(arr,arr+n);
        arr[n]=arr[0];
        for(int i=0;i<n;i++){
        	pts=polycut(pts,arr[i],arr[i+1]);
        }
        printf("Floor #%d\n",++F);
        if(pts.size()==0){
          printf("Surveillance is impossible.\n");
        }else{
         printf("Surveillance is possible.\n");
        }
        puts("");
    }



}