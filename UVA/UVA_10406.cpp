/**
*   @Author : MeGaCrazy
*   @InitTime : Sat Jun 16 04:02:19 2018
*   @Idea :   First instead of finding the new area directly we will get the area of removed parts and  
*             substract it from the whole area ..
*             How to get the Removed area..For each edge we can calculate the new area of new edge corresbonding to this edge
*             Just we caculate the removed distance from the orginial part and culculate the area like in this figure :
*             link : shorturl.at/imuJ1  
*             so we caculate the angle using dot product and then get the removed part then calcuate the rectangle area for each edge
*             and then substract from the original area that's it 
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double d;
int n;

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
  point operator -(double other){
  	return point(x-other,y-other);
  }


};
const int N=100005;
point arr[N];
double cross(point &v1,point &v2){
	return v1.x*v2.y-v1.y*v2.x;
}
double dot(point &v1,point &v2){
	return v1.x*v2.x+v1.y*v2.y;
}
double norm(point v){
	return sqrt(dot(v,v));
}
double Angle(point &v1,point &v2){     																				
      return acos(dot(v1,v2)/sqrt(dot(v1,v1)*dot(v2,v2)));
}
const double EPS=1e-9,PI=acos(-1);
double cut(){
	double ret=0;
	vector<double>x(n+1,0);
       for(int i=0;i<n;i++){
           point a=arr[i];
           point b=arr[(i+1)%n];
           point c=arr[(i-1+n)%n];
           point v1=b-a;
           point v2=c-a;
           double angle=Angle(v1,v2);
           if(fabs(angle-PI) <EPS){
           		continue;
           }
//           cout<<angle<<endl;
           x[i]=d/tan(angle/2.0);         // get removed part
       }
       x[n]=x[0];
       for(int i=0;i<n;i++){
          ret+=norm(arr[i+1]-arr[i])-x[i];             // get the length of after remove the ignored part
       }
       return ret*d;             // get the rectangles' area         
	
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    while(scanf("%lf %d",&d,&n),(n)){
    	  for(int i=0;i<n;i++){
    	  	scanf("%lf %lf",&arr[i].x,&arr[i].y);
    	  }
    	  arr[n]=arr[0];
    	  double ans=0;
    	  for(int i=0;i<n;i++){
    	  	ans+=cross(arr[i],arr[(i+1)%n]);
    	  }
    	  printf("%.3f\n",(abs(ans)/2.0) - cut());
    }



}