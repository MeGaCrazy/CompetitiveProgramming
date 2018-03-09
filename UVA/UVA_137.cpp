/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Mar 09 06:22:04 2018
*   @Idea :   WA
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
const int N=1e5+7;
bool visit[N];
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
  inline bool operator ==(point &other){
     return fabs(x-other.x) <EPS && fabs(y-other.y) <EPS;
  }
};
int n;

int dcmp(double x,double y){
   return fabs(x-y) < EPS?0:x>y?1:-1;
}
double dis(double x,double y,double xx,double yy){
       return sqrt((x-xx)*(x-xx)+(y-yy)*(y-yy));
}
double norm(point &v1){
      return sqrt((v1.x*v1.x) +(v1.y*v1.y));
}
double cross(point &v1,point &v2){
   return v1.x*v2.y - v1.y*v2.x;
}

int ccw(point &a,point &b,point &c){
    point v1=b-a;
    point v2=c-a;
    if(cross(v1,v2) <-EPS)return -1;
    if(cross(v1,v2) > EPS)return 1;
    if(v1.x*v2.x < -EPS || v1.y*v2.y < -EPS)return -1;
    if(norm(v1) < norm(v2) -EPS)return 1;
    return 0;
}



pair<int,point> InterSeg(point &a,point &b,point &c,point &d){
    point u=b-a;
    point v=d-c;
    point w=a-c;
    double t=cross(v,w)/cross(u,v);
    if(isnan(t)||isinf(t))return make_pair(0,point());
    return make_pair(1,(u*t)+a);
}
bool Inter(point &a,point &b,point &c,point &d){
    bool f1=(b==a),f2=(c==d);
    if(f1&&f2)return c==a;
    if(f1) return ccw(c,d,a)==0;
    if(f2) return ccw(a,b,c)==0;
    return ccw(a,b,c)*ccw(a,b,d)<=0&&
           ccw(c,d,a)*ccw(c,d,b)<=0;
}
bool onpoly(vector<point>&v,point &pt){
     int cnt=0;
     for(int i=0;i<(int)v.size();i++){
          point cur=v[i];
          point nxt=v[(i+1)%v.size()];
          if(ccw(cur,nxt,pt)==0)return 0;
          point v1=nxt-cur;
          point v2=pt-cur;
          if(cur.y <= pt.y){
              if(nxt.y  > pt.y && cross(v1,v2) >0)cnt++;
          }else{
              if(nxt.y <= pt.y && cross(v1,v2) <0)cnt--;
          }
     }
     return cnt!=0;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   freopen("out","w",stdout);
#endif
   while(scanf("%d",&n),n){

       memset(visit,0,sizeof(visit));
       vector<point>arr1,arr2;
       point pt;
       for(int i=0;i<n;i++){
          scanf("%lf %lf",&pt.x,&pt.y);
          arr1.push_back(pt);
       }
       scanf("%d",&n);
       for(int i=0;i<n;i++){
         scanf("%lf %lf",&pt.x,&pt.y);
         arr2.push_back(pt);
       }
       vector<point>f;
       double area1=0;
       for(int i=0;i<(int)arr1.size();i++){
          if(onpoly(arr2,arr1[i])){
             f.push_back(arr1[i]);
          }
          int ii=(i+1)%arr1.size();
          area1+=cross(arr1[i],arr1[ii]);
       }
       double area2=0;
       for(int i=0;i<(int)arr2.size();i++){
         if(onpoly(arr1,arr2[i])){
            f.push_back(arr2[i]);
         }
          int ii=(i+1)%arr2.size();
          area2+=cross(arr2[i],arr2[ii]);
       }
       area1/=2.0,area2/=2.0;
       set<pair<int,int> >s;
       for(int i=0;i<(int)arr1.size();i++){
          for(int j=0;j<(int)arr2.size();j++){
              int ii=(i+1)%(int)arr1.size();
              int jj=(j+1)%(int)arr2.size();
              if(Inter(arr1[i],arr1[ii],arr2[j],arr2[jj])){
                pair<int,point>ret=InterSeg(arr1[i],arr1[ii],arr2[j],arr2[jj]);
                if((ret.second==arr1[i]||ret.second==arr1[ii]||ret.second==arr2[j]||ret.second==arr2[jj])){
                    if(s.count(make_pair(ret.second.x,ret.second.y))==1)continue;
                    else s.insert(make_pair(ret.second.x,ret.second.y));
                }
                if(ret.first==1)f.push_back(ret.second);
              }
          }
       }
         
       if(!(int)f.size()){
         printf("%8.2f",fabs(area1)+fabs(area2));
         continue;
       }
   //    for(point u:f){
     //    cerr<<u.x<<" "<<u.y<<endl;
      // }

       vector<point>poly;
       poly.push_back(f[0]);
       visit[0]=1;
       int cnt=1;
       int need=f.size();
       while(cnt!=need){
           point cur=poly.back();
           double best=2e18;
           int besti=-1;
           for(int i=0;i<f.size();i++){
              if(visit[i])continue;
              double tt=dis(cur.x,cur.y,f[i].x,f[i].y);
              if(dcmp(tt,best)==-1){
                besti=i;
                best=tt;
              }
           }
           cnt++;
           visit[besti]=1;
           poly.push_back(f[besti]);
       }
       poly.push_back(poly[0]);
       double ans=0;
       for(int i=0;i<(int)poly.size()-1;i++){
           ans+=cross(poly[i],poly[i+1]);
//           cerr<<poly[i].x<<" "<<poly[i].y<<" "<<poly[i+1].x<<" "<<poly[i+1].y<<endl;
       }
       ans/=2.0;
       ans=fabs(area1)+fabs(area2)-2.0*fabs(ans);
       printf("%8.2f",ans); 
    }
    cout<<endl;

}