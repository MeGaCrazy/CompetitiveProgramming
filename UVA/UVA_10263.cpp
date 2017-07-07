#include <bits/stdc++.h>
/*
*  target: get position on segment  such that the distance between it and point M is minimal
*  sol : make 2 vectors get projection length of one on another and then make scale for this line that the projection length is on it
*         and then add end point of vector to make him on the line again ..
*        a like this formula c(new point)=u*ab+a;
* 
*/
using namespace std;
const int N=12345;
struct point{
    double x,y;
    point():x(1e9),y(1e9){}
    point(double xx,double yy):x(xx),y(yy){}
};
point arr[N];
struct vec{
    double x,y;
    vec(double xx,double yy):x(xx),y(yy){}
};
double dis(point p1,point p2){
    return hypot(p1.x-p2.x,p1.y-p2.y);
}
vec to_vec(point p1,point p2){
         return vec(p2.x-p1.x,p2.y-p1.y);
}
double dot(vec a,vec b){
         return (a.x*b.x+a.y*b.y);
}
point scale(vec a,double u){
     return point(a.x*u,a.y*u);
}
double norm_seq(vec a){
     return (a.x*a.x+a.y*a.y);
}
point translate(point a,point b){
       return point(b.x+a.x,b.y+a.y);
}
double distToLine(point p, point A, point B, point &c) {
	vec Ap = to_vec(A, p), AB = to_vec(A, B);
	double u = dot(Ap, AB) / norm_seq(AB);
	c = translate(A, scale(AB, u));
	return dis(p, c);
}

double distToLineSegment(point p, point A, point B, point &c) {
	vec Ap = to_vec(A, p), AB = to_vec(A, B);
	double u = dot(Ap, AB) / norm_seq(AB);
	if (u < 0.0) {
		c = point(A.x, A.y);
		return dis(p, A);
	}
	if (u > 1.0) {
		c = point(B.x, B.y);
		return dis(p, B);
	}
	return distToLine(p, A, B, c);
}
int main(){
#ifndef ONLINE_JUDGE
      freopen("in.txt","r",stdin);
#endif
      point m;
      while(scanf("%lf %lf",&m.x,&m.y)==2){
         int n;
         scanf("%d",&n);
         double x,y;
         for(int i=0;i<=n;i++){
            scanf("%lf %lf",&x,&y);
            arr[i]=point(x,y);
         }
         double ans=1e9;
         point ans_point,tp;
         for(int i=0;i<n;i++){
             double tmp=distToLineSegment(m,arr[i],arr[i+1],tp);
             if(tmp-ans<1e-8){
                 ans=tmp;
                 ans_point=tp;
             }
         }
         printf("%.4lf\n%.4lf\n",ans_point.x,ans_point.y);
      }
}
