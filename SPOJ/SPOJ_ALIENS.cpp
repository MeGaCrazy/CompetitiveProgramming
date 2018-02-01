/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Feb 01 04:40:00 2018
*   @Idea :    Just Using welzl algorithm to get Minimum Enclosing Circle 
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
  point():x(0),y(0){}
  point(double a,double b):x(a),y(b){}
  point operator -(point a){
      return point(x-a.x,y-a.y);
  }
  point operator +(point a){
     return point(x+a.x,y+a.y);
  }
  point operator *(double f){
        return point (x*f,y*f);
  }
};
const int N=100005 ;
const double EPS=1e-6;
point arr[N];
point f[5];
point center;
double rad;
double dis(point a){
    return sqrt((a.x)*(a.x)+(a.y)*(a.y));
}          
int dcmp(double x,double y){
   return fabs(x-y)<EPS?0:x>y?1:-1;
}
double cross(point a,point b){
     return a.x*b.y-a.y*b.x;
}
int interSeg(point a,point b,point c,point d,point &ret){
   point u=b-a;
   point v=d-c;
   point w=a-c;
   double f=cross(u,v);
   if(f==0){
    return -1;
   }
   double f1=cross(v,w);
   double f2=cross(u,w);
   double t1=f1/f;
   ret=a+(b-a)*t1;
   return 1;
}
pair<double,point> findCircle(point a,point b,point c){
         point v1=b-a;
         point v2=c-a;
         point mid1=(b+a)*.5;
         point mid2=(c+a)*.5;
         point prv1=point(v1.y,-v1.x);
         point prv2=point(v2.y,-v2.x);
         point end1=prv1+mid1;
         point end2=prv2+mid2;
         point inter;
         interSeg(mid1,end1,mid2,end2,inter);
         return make_pair(dis(a-inter),inter);
}      
void MEC(int n,int r){
   if(n==0&&r==2){
      center=(f[0]+f[1])*0.5;
      rad=dis(f[0]-center);
	
   }else if(r==3){
      pair<double,point>circ=findCircle(f[0],f[1],f[2]);
      center=circ.second;
      rad=circ.first;
   }else if(n==0){
      center=f[0];
      rad=0;
   }else{
      MEC(n-1,r);
      if(dcmp(dis(arr[n-1]-center),rad)==1){
          f[r]=arr[n-1];
          MEC(n-1,r+1);
      }	
   }
                    
}


int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
//   freopen("out","w",stdout);
#endif
      int t;
      scanf("%d",&t);
      while(t--){
         int n;
         scanf("%d",&n);
         memset(f,0,sizeof(f));
	     rad = 0;
         for(int i=0;i<n;i++){
           scanf("%lf %lf",&arr[i].x,&arr[i].y);
         }
         random_shuffle(arr,arr+n);
         MEC(n,0);
         printf("%.2f\n%.2f %.2f\n",rad,center.x,center.y);
      }

}