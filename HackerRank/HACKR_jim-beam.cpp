/**
*   @Author : MeGaCrazy
*   @InitTime : Mon Jan 29 04:39:43 2018
*   @Idea : Just Check If There is Intersection Or Not :)
*   Corner Case : Take Care Of Overflows Issues
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  long long x,y;
  point():x(0),y(0){}
  point(int xx,int yy):x(xx),y(yy){}
};
long long Cross(point a,point b,point c){
     return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);	
}
bool Onsegment(point a,point b,point c){
    return (min(a.x,b.x)<=c.x&&c.x<=max(a.x,b.x)&&
           min(a.y,b.y)<=c.y&&c.y<=max(a.y,b.y));
}
bool Intersect(point a,point b,point c,point d){
    long long abc=Cross(a,b,c);
    long long abd=Cross(a,b,d);
    long long cda=Cross(c,d,a);
    long long cdb=Cross(c,d,b);
    if (((abc>0 && abd<0) || (abc<0 && abd>0)) &&
			((cda>0 && cdb<0) || (cda<0 && cdb>0)))
			return true;

    if(abc==0&&Onsegment(a,b,c))return 1;
    if(abd==0&&Onsegment(a,b,d))return 1;
    if(cda==0&&Onsegment(c,d,a))return 1;
    if(cdb==0&&Onsegment(c,d,b))return 1;
    return 0;
}
int main(){
//#ifndef ONLINE_JUDGE
 //  freopen("in","r",stdin);
 //  freopen("out","w",stdout);
//#endif
   int t;
   scanf("%d",&t);
   while(t--){
      point a,b,m;
      scanf("%lld %lld %lld %lld %lld %lld",&a.x,&a.y,&b.x,&b.y,&m.x,&m.y);
      puts((Intersect(point(),m,a,b))?"NO":"YES");
   }

}