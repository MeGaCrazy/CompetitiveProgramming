/*
*    Idea : Just try to move in rounds if at round the difference between us is x( your time to take round )
*           for clearness i mean in which round the speedest one will catch you :)  
*
*
*/
#include <bits/stdc++.h>
using namespace std;




int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
      int x,y;
      while(scanf("%d %d",&x,&y)==2){
         int xx=0,yy=0,ans=1;
         while(1){
            if((yy-xx)>=x)break;
            ans++;
            xx+=x,yy+=y;
         }
         printf("%d\n",ans);
      
      }



}