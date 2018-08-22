/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Aug 16 05:13:25 2018
*   @Idea :  Just using trigonometry rules
*            1- Get the corrspond angle from the object
*            2- make 2 vectors with new angles
*            3- get the intersection point of two vector
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
 point operator +(point &other){
 	return point(x+other.x,y+other.y);
 }
 point operator *(double f){
 	return point(x*f,y*f);
 }

};
double cross(point &v1,point &v2){
	return v1.x*v2.y-v1.y*v2.x;
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
     while(t--){
        point pt[2];
        int d[2];
        for(int i=0;i<2;i++){
        	scanf("%lf %lf %d",&pt[i].x,&pt[i].y,&d[i]);
        }

        double angle=(90-d[0])*acos(-1)/180.0;
        point u=point(100.0*cos(angle),100.0*sin(angle));
        angle=(90-d[1])*acos(-1)/180.0; 
        point v=point(100.0*cos(angle),100.0*sin(angle));
        point w=pt[0]-pt[1];
        double t=cross(v,w)/cross(u,v);
        point ret=u*t+pt[0];
        printf("%.4f %.4f\n",ret.x,ret.y);
     	
     }



}