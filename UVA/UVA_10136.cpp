/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Aug 22 04:53:22 2018
*   @Idea : Just get intersection point between two circle and make a circle with intersection point as it's center 
*            then  calculate how many point inside it :) 
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
double EPS=1e-6;
struct point{
  double x,y;
  point(double x=0,double y=0):x(x),y(y){}
  point operator -(point other){
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
vector<point>pts;
double Radius=2.5;
vector<point>inters;
int dcmp(double a,double b){
	return fabs(a-b) < EPS?0:a>b?1:-1;
}
double fixangle(double t){
 	return t>1?1:t<-1?-1:t;
}
double Angle(point v){
	return atan2(v.y,v.x);
}
double get_angle(double a,double b,double c){
	double t=b*b+c*c-a*a;
	t/=(2*b*c);
	return acos(fixangle(t));
}
double length(point v){
	return sqrt((v.x*v.x)+(v.y*v.y));
}

double dis(point &v1,point &v2){
	return (v1.x-v2.x)*(v1.x-v2.x)+(v1.y-v2.y)*(v1.y-v2.y);
}
void circleInter(point &a,point &b){
	if(a==b)return;
	double ang1=Angle(b-a),ang2=get_angle(Radius,length(b-a),Radius);
	if(::isnan(ang2)){
		ang2=0; 
	}
	point v=point(a.x+Radius*cos(ang1+ang2),a.y+Radius*sin(ang1+ang2));
	if(dcmp(dis(v,a),Radius*Radius)!=0||dcmp(dis(v,b),Radius*Radius)!=0){
		return;
	}
	inters.push_back(v);
	v=point(a.x+Radius*cos(ang1-ang2),a.y+Radius*sin(ang1-ang2));		
	if(inters[0]==v){
	 return;		
	}
	inters.push_back(v);
		
}

long long contains(point &a){
	long long  ret=0;
  	for(int i=0;i<pts.size();i++){
  		if(dcmp(length(pts[i]-a),Radius)!=1)ret++;
  	}
  	return ret;	
}


long long solve(point &a,point &b){
	inters.clear();
	circleInter(a,b);
	long long ret=0;
	for(int i=0;i<inters.size();i++){
           ret=max(ret,contains(inters[i]));   	
	}
	return ret;

}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
     int t;
     scanf("%d",&t);
             string s;
     cin.ignore();
     getline(cin,s);
     while(t--){
     	pts.clear();
        
        double a,b;
        string prev;
        while(getline(cin,s)&&s!=""){
          if(s==prev)break;
          istringstream in(s);
          prev=s;
          in>>a>>b;
          pts.push_back(point(a,b));
        }
        long long ans=1;
        for(int i=0;i<pts.size();i++){
	   for(int j=i+1;j<pts.size();j++){
	     	ans=max(ans,solve(pts[i],pts[j]));
	   }	                         	
        }
        cout<<ans<<endl;
        if(t){
          cout<<endl;
        }
          	
     
     }




}