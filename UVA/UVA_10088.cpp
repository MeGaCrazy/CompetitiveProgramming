/**
*   @Author : MeGaCrazy
*   @InitTime : Fri Jun 29 05:46:06 2018
*   @Idea :   Just use pick therom
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;

int n;
const double EPS=1e-5;
const int N=1005;

struct point{
  long long x,y;
  point(long long x=0,long long y=0):x(x),y(y){}
  point operator -(point &other){
    	return point(x-other.x,y-other.y);
  }
  point operator +(point &other){
  	return point(x+other.x,y+other.y);
  }
  point operator *(int f){
  	return point(x*f,y*f);
  }
  bool operator ==(point &other){
  	return x==other.x&&y==other.y;
  }
};
long long cross(point &v1,point &v2){
	return v1.x*v2.y-v1.y*v2.x;
}
point arr[N];
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     while(scanf("%d",&n),n){
        for(int i=0;i<n;i++){
        	scanf("%d %d",&arr[i].x,&arr[i].y);
        }
        arr[n]=arr[0];
        long long area=0;
        for(int i=0;i<n;i++){
        	area+=cross(arr[i],arr[i+1]);
        }		
        area=abs(area)/2.0; 
        long long e=0;
        for(int i=0;i<n;i++){
             point slope=arr[i+1]-arr[i];
             int divide=__gcd(abs(slope.x),abs(slope.y));
             e+=divide;
        }
        long long ans=area-e/2+1;   // pick formula
        printf("%lld\n",ans);		
     }



}