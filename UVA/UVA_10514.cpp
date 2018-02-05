/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Feb 05 07:29:51 2018
*   @Idea :
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
  point(double X,double Y):x(X),y(Y){}
  point operator -(point &other){
    return point(x-other.x,y-other.y);
  }
    point operator +(point &other){
    return point(x+other.x,y+other.y);
  }

  inline bool operator ==(point &other){
     return x==other.x&&y==other.y;
  }
};
const int N=105;
const double EPS=1e-9;
point arr[N][2];
point iso[12][25];
double cost[25][25];
int sz[12];
struct seg{
  point a,b;
  seg(point &A,point &B):a(A),b(B){}
  seg() :a(point(0, 0)), b(point(0, 0)) {}
};
seg ft[25];
seg se[25];
double dis(double x,double y,double xx,double yy){
 return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
double dot(point v1,point v2){
    return v1.x*v2.x + v1.y*v2.y;
}
double cross(point v1,point v2){
    return v1.x*v2.y - v1.y*v2.x;
}
double disToLine(point &f,seg &s){
      if(s.a==s.b)return dis(f.x,f.y,s.a.x,s.a.y);
      return abs(cross(f-s.a,s.b-s.a))/dis(s.a.x,s.a.y,s.b.x,s.b.y);
} 
double disToSeg(point &f,seg &s){
     if( dot(f-s.a,s.b-s.a)<=0)return dis(f.x,f.y,s.a.x,s.a.y);
     if( dot(f-s.b,s.b-s.a) >=0)return dis(f.x,f.y,s.b.x,s.b.y);
     return disToLine(f,s);
}
double disIsland(int idx1,int idx2){
      double ret=1e9;
      int len1=0,len2=0;
      for(int i=0;i<sz[idx1];i++){
         ft[i]=seg(iso[idx1][i],iso[idx1][(i+1)%sz[idx1]]); 
         len1++;
      }	
      for(int i=0;i<sz[idx2];i++){
         se[i]=seg(iso[idx2][i],iso[idx2][(i+1)%sz[idx2]]);
         len2++;
      }
      
      // vertex idx1 to seg idx2
      for(int i=0;i<sz[idx1];i++){
         for(int j=0;j<len2;j++){
             double tmp=disToSeg(iso[idx1][i],se[j]);
//             cerr<<tmp<<" "<<idx1<<" "<<idx2<<endl;
             if( tmp < ret+EPS){
                ret=tmp;
             }
         }
      }
      
     
    // vertex idx2 to seg idx1
    for(int i=0;i<sz[idx2];i++){
        for(int j=0;j<len1;j++){
          double tmp=disToSeg(iso[idx2][i],ft[j]);
          if( tmp < ret+EPS){
                ret=tmp;
           }
        } 
    }
    
   return ret;
}
int main(){
#ifndef	ONLINE_JUDGE
   freopen("in","r",stdin);
  // freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
        int r1,r2,n;
        scanf("%d %d %d",&sz[0],&sz[1],&n);
        for(int i=0;i<sz[0];i++){
           scanf("%lf %lf",&iso[0][i].x,&iso[0][i].y);
        }
        for(int i=0;i<sz[1];i++){
           scanf("%lf %lf",&iso[1][i].x,&iso[1][i].y);
        }
        n+=2;
        for(int i=2;i<n;i++){
             scanf("%d",&sz[i]);
             for(int j=0;j<sz[i];j++){
                scanf("%lf %lf",&iso[i][j].x,&iso[i][j].y);
             }
        }
        for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
                if(i==j)cost[i][j]=0;
		else cost[i][j]=disIsland(i,j);
           }
        }
        // End input
         for(int k=0;k<n;k++){          // floyd for islands
            for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                  if(cost[i][k]+ cost[k][j] < cost[i][j] +EPS){
			cost[i][j]= cost[i][k]+ cost[k][j];
                  }
               }
            }
         }
         printf("%.3f\n",cost[0][1]);
     }

}