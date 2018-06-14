/**
*   @Author : MeGaCrazy
*   @InitTime : Thu Jun 14 19:51:50 2018
*   @Idea :  First of all lets put our target 
*            (Target) ->  Check number of ways That if we can divide the polygon in two (integer) halves
*            So When polygon area can divide by /2 and still integer the answer is obvious if the area is "Even"
*            Cool :)
*            some math tricks (Even (+|-) Even or  odd (+|-) odd) = Even
*            now we iterate for each vertex in the polyon and check how many previous vertex can connected with
*            and we have cumlative sum that check the current cummlative is Even Or Odd
*            So we have 4 possible point i can connected  that its x and y are
*             1 1  
*             1 0        0 mean even , 1 mean odd  that of course from odd and even prespective 
*             0 1
*             0 0
*             now  if the cumlative sum  up to edge that I current vertex equal is "ODD"
*             I should  connect to point that make the divided polygon even
*             like that  
*                   currently edge(ODD)  |        |  (ODD)The Edge that I will connect to it's point
*                                        |        |
*                      then I should connect to point that edge is even 
*                      ODD |------ | ODD 
*                      	   | even  |
*                          |       | 
*  
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
struct point{
  int x,y;
//  point():x(0),y(0){}
  point(int x=0,int y=0):x(x),y(y){}
};
const int N=2e5+7;
point arr[N];
int n;
int crossCheck(point a,point b){
     return (a.x&b.y)^(a.y&b.x);
}
int main(){

   freopen("integral.in","r",stdin);
   freopen("integral.out","w",stdout);

    scanf("%d",&n);
    for(int i=0;i<n;i++){
    	scanf("%d %d",&arr[i].x,&arr[i].y);
    	arr[i].x=(arr[i].x%2+2)%2;
    	arr[i].y=(arr[i].y%2+2)%2;
    }
    arr[n]=arr[0];
        long long ans=0;
    int cnt[2][2][2]={};
    int sum=0;
    for(int i=1;i<=n;i++){
       sum^=crossCheck(arr[i],arr[i-1]);  
       for(int j=0;j<2;j++){
       	  for(int k=0;k<2;k++){
       	      int id=crossCheck(arr[i],point(j,k));
       	      ans+=cnt[sum^id][j][k];
       	  }
       }
       ans--;      // to remove adjcent
       cnt[sum][arr[i].x][arr[i].y]++;
    }
    if(sum)printf("0\n");
    else printf("%lld",ans);


}