/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Feb 16 18:03:25 2018
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
const double EPS=1e-5;
struct point{
 double x,y;
 point(double x=0,double y=0):x(x),y(y){}
 point operator -(point &other){
     return point(x-other.x,y-other.y);
 }
 inline bool operator ==(point &other){
     return x==other.x&&y==other.y;
 }
 bool operator <(point &other){
    return ((y < other.y -EPS)||(fabs(y-other.y) < EPS && x < other.x -EPS));
 }
 point operator *(double f){
   return point(x*f,y*f);
 }
 point operator +(point &other){
   return point(x+other.x,y+other.y);
 }                                  
};
struct seq{
  point pt[4];
  double cx,cy,r;
  bool operator <(seq &other){
     return r > other.r +EPS;
  }
};
const int N=105;
seq arr[N];
bool full[N];

double cross(point &v1,point &v2){
  return v1.x*v2.y - v1.y*v2.x;
}
double norm(point &v){
   return sqrt((v.x*v.x) +(v.y*v.y));
}

int ccw(point &a,point &b,point &c){
   point v1=b-a;
   point v2=c-a;
 //     cerr<<"U :"<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<" "<<c.x<<" "<<c.y<<" "<<cross(v1,v2)<<endl;
   if(cross(v1,v2) >EPS)return 1;
   if(cross(v1,v2) < -EPS)return -1;
   if(v1.x*v2.x < -EPS || v1.y *v2.y < -EPS)return -1;
   if(norm(v1) < norm(v2) -EPS)return 1;
   return 0;
}
bool isInter(point &a,point &b,point &c,point &d){
   bool f1=(b==a),f2=(c==d);
   if(f1&&f2)return c==a;
   if(f1) return ccw(c,d,a)==0;
   if(f2) return ccw(a,b,d)==0;
   return ccw(a,b,c)*ccw(a,b,d)<=0&&
          ccw(c,d,a)*ccw(c,d,b)<=0;
}
pair<bool,point> InterSeg(point &a,point &b,point &c,point &d){
     point u=b-a;
     point v=d-c;
     point w=a-c;
     double down=cross(u,v);
     if(down==0)return make_pair(0,point());
     double t1=cross(v,w)/down;
     if(t1 < -EPS || t1 > 1)return make_pair(0,point());
     point ret=(u*t1)+a;
     return make_pair(1,ret);
}
bool Valid(vector<point>&v,point &a){
    for(int i=0;i<(int)v.size();i++){
      if(fabs(v[i].x-a.x)<EPS&&fabs(v[i].y-a.y)<EPS)return 0;
    }
    return 1;
}
double common(int idx1,int idx2){ 
      vector<point>v;
      // first
      for(int i=0;i<4;i++){
        bool f=1;
         for(int j=0;j<4;j++){
            if(ccw(arr[idx1].pt[(j)%4],arr[idx1].pt[(j+1)%4],arr[idx2].pt[i])<0)f=0;
         }
         if(f&&Valid(v,arr[idx2].pt[i]))v.push_back(arr[idx2].pt[i]);
     }
      //second

      for(int i=0;i<4;i++){
        bool f=1;
         for(int j=0;j<4;j++){
            if(ccw(arr[idx2].pt[(j)%4],arr[idx2].pt[(j+1)%4],arr[idx1].pt[i])<0)f=0;
         }
         if(f&&Valid(v,arr[idx1].pt[i]))v.push_back(arr[idx1].pt[i]);
     }	
     // common
     for(int i=0;i<4;i++){
          for(int j=0;j<4;j++){
             if(isInter(arr[idx1].pt[i],arr[idx1].pt[(i+1)%4],arr[idx2].pt[j],arr[idx2].pt[(j+1)%4])){
                 pair<int,point> ret=InterSeg(arr[idx1].pt[i],arr[idx1].pt[(i+1)%4],arr[idx2].pt[j],arr[idx2].pt[(j+1)%4]);
               //  cerr<<"ret"<<ret.x<<" "<<ret.y<<endl;
                 if(ret.first==1&&Valid(v,ret.second))v.push_back(ret.second);
             }
          }
      }
      if(v.size() < 4)return 0;
      sort(v.begin(),v.end());
      swap(v[2],v[3]);
      //cerr<<" idx :"<<idx1<<" "<<idx2<<endl;
  //    cerr<<"size "<<v.size()<<endl;
   //   for(int i=0;v.size()>4&&i<(int)v.size();i++){
   //     point a=v[i];
 //       cerr<<a.x<<" "<<a.y<<endl;
 //     }
 
      return (v[2].x-v[0].x)*(v[2].y-v[0].y);
}

bool Inter(int idx1,int idx2){
     for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
            if(isInter(arr[idx1].pt[i],arr[idx1].pt[(i+1)%4],arr[idx2].pt[j],arr[idx2].pt[(j+1)%4]))return 1;
         }
     }
     return 0;

}

bool contain(int idx1,int idx2){
     for(int i=0;i<4;i++){
         for(int j=0;j<4;j++){
            if(ccw(arr[idx1].pt[(i)%4],arr[idx1].pt[(i+1)%4],arr[idx2].pt[j])<0)return 0;
         }
     }
     return 1;
}
double dx[]={1,-1,1,-1};
double dy[]={1,1,-1,-1};
void modify(int idx){
      for(int i=0;i<4;i++){
          double nx=arr[idx].cx+(dx[i]*arr[idx].r),ny=arr[idx].cy+(dy[i]*(arr[idx].r));
          arr[idx].pt[i]=point(nx,ny);
      }
      sort(arr[idx].pt,arr[idx].pt+4);
      swap(arr[idx].pt[2],arr[idx].pt[3]);
}   
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int n,cnt=1;
     while(scanf("%d",&n),n){
        memset(full,0,sizeof(full));
        for(int i=0;i<n;i++){
          scanf("%lf %lf %lf",&arr[i].cx,&arr[i].cy,&arr[i].r);
          modify(i);
        }

        sort(arr,arr+n);
        for(int i=0;i<n;i++){
          for(int j=0;j<i;j++){
             if(contain(j,i)){
               full[i]=1;
             //  cerr<<"full "<<i<<endl;
               break;
             }
          }
        }

        double ans=0;
        for(int i=0;i<n;i++){
           if(full[i])continue;
           double cnt=(arr[i].r*2)*(arr[i].r*2);
           for(int j=0;j<i;j++){
              if(Inter(i,j)){
                   cnt-=common(i,j);
                   if(cnt <0)break;
              }
           }
           if(cnt>0)ans+=cnt;
        }
        printf("%d %.2f\n",cnt++,ans);
     }

}