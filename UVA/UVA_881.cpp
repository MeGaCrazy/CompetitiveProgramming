/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Mar 06 17:33:15 2018
*   @Idea :   Check if point inside the poylgon using Winding number algorithm
*             and Take the closer polygon to the point Just Check if this polygon is inside your answer polygon
*             Take it ...
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
};
double EPS=1e-5;

double dis(point &v1,point &v2){
   return sqrt((v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y));
}
double norm(point &v){
    return sqrt(v.x*v.x+v.y*v.y);
}

double cross(point &v1,point &v2){
    return v1.x*v2.y - v1.y*v2.x;
}

int ccw(point &a,point &b,point &c){
  point v1=b-a;
  point v2=c-a;
  if(cross(v1,v2) >EPS)return 1;
  if(cross(v1,v2) < -EPS)return -1;
  if(v1.x*v2.x < -EPS || v1.y *v2.y < -EPS)return  -1;
  if(norm(v1) < norm(v2) -EPS)return 1;
  return 0;
}

bool onpoly(vector<point>&v,point &pt){
     int n=v.size();
     int cnt=0;
     for(int i=0,j=n-1;i<n;j=i++){
         point v1=v[i]-v[j];
         point v2=pt-v[j];
         if(ccw(v[j],v[i],pt)==0)return 1;
         if(v[j].y <= pt.y){
             if(v[i].y > pt.y && cross(v1,v2) >EPS){
              cnt++;
             }
         }else {
           if(v[i].y <= pt.y && cross(v1,v2) < -EPS)
            cnt--;
         }
     }
     return cnt!=0;
}

int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
    scanf("%d",&t);
     while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,vector<point> > >v;
        cin.ignore();
        string s;
        for(int i=0;i<n;i++){
            getline(cin,s);
            stringstream in(s);
            int id;
            double x,y;
            in>>id;
            vector<point>tmp;
            while(in>>x>>y){
               tmp.push_back(point(x,y));
            }
            v.push_back(make_pair(id,tmp));
        }
        int q;
        scanf("%d",&q);
        vector<pair<int,int> >ans;
        while(q--){
          point pt;
          int qid;
          scanf("%d %lf %lf",&qid,&pt.x,&pt.y);
          int sol=-1;
          for(int i=0;i<n;i++){
             if(onpoly(v[i].second,pt)&&(sol==-1||onpoly(v[sol].second,v[i].second[2]))){
                sol=i;
             }
          }
          ans.push_back(make_pair(qid,sol==-1?0:v[sol].first));
        }
        sort(ans.begin(),ans.end());
        for(pair<int,int>u:ans){
            printf("%d %d\n",u.first,u.second);
        }
       if(t)puts(""); 
     }



}