/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Jun 16 04:02:19 2018
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
    int d,n;

struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point &other){
  	return point(x-other.x,y-other.y);
  }
  point operator +(point &other){
  	return point(x+other.x,y+other.y);
  }
  point operator /(double other){
  	return point(x/other,y/other);
  }
                                       
  point operator *(double other){
  	return point(x*other,y*other);
  }

};
const int N=10005;
point arr[N];
double cross(point &v1,point &v2){
	return v1.x*v2.y-v1.y*v2.x;
}
double dot(point &v1,point &v2){
	return v1.x*v2.x+v1.y*v2.y;
}
void normalize(point &v){
	double length=sqrt(dot(v,v));
      v=v/length;
}
vector<point>new_poly(){
	vector<point>ret;
       for(int i=0;i<n;i++){
         point a=arr[i];
         point b=arr[(i+1)%n];
         point c=arr[(i-1+n)%n];
         point v1=b-a;
         point v2=c-a;
         point v=(v1+v2)/2.0;
         normalize(v);
         double dd=sqrt(2)*1.0*d;
         point end=(v*dd)+a;
         ret.push_back(end);
       }
       return ret;
	
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    while(scanf("%d %d",&d,&n),(d+n)){
    	  for(int i=0;i<n;i++){
    	  	scanf("%lf %lf",&arr[i].x,&arr[i].y);
    	  }
    	  arr[n]=arr[0];
    	  vector<point>ret=new_poly();
    	  double ans=0;
    	  for(int i=0;i<ret.size();i++){
    	  	ans+=cross(ret[i],ret[(i+1)%n]);
    	  }
    	  printf("%lf\n",fabs(ans)/2.0);
    }



}