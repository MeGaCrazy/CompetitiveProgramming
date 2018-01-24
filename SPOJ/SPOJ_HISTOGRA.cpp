/**                                                                                                  |
*   @Author : MeGaCrazy                                                                            | |
*   @InitTime : Sat Jan 20 00:51:27 2018                                                           | |
*   @Idea :  Now let's imagine that the histogram have 4 element and the first three like this   | | | 
*            now if the last element is like this |   what the areas I can calculate
*                                                 |
*                                        |         
*          now the histogram like this | | 
*                                      | | |
*                                    | | | |   now if the height behind last element higher than him then will get his height
*                                      _____
*                                      if i want to get area for last element all height behind him and higher than his height will be = 2 
*
*          So Now >>>> I Only Care Where The First Element Behind me and less than me in height 
*          So in last example if i want to add last element I want to know that (1,1)
*                                                                                pos height
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
  // freopen("in","r",stdin);
 //  freopen("out","w",stdout);
#endif
      int n;
      scanf("%d",&n);
      stack<pair<int,int> >s;
      s.push(make_pair(0,0));
      long long ans=0;
      for(int i=1;i<=n+1;i++){
      	   int a;
       	   if(i<=n)scanf("%d",&a);
       	   else a=0;
       	   int j=i;
      	   while(a < s.top().first){
      	      j=s.top().second;
      	     int height=s.top().first;
      	     s.pop();
	     long long tmp= 1ll*height*(i-j);
	     if(tmp > ans)ans=tmp;
      	   }
      	   if(a > s.top().first){
      	       s.push(make_pair(a,j));
      	   }
     }
     printf("%lld\n",ans);
}