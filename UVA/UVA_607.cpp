/*
*    Idea : U can get how many lecture should teach by greedy because he said they must take him prequisites :)
*           Then calcaluting the recurrence of dp not hard Just take as mush as u can from lecture then recurrce to another lecture
*           if number of Lec reach 0 and we teach all topcis it's One of Sub Solution
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
int dp[N][N];
int arr[N];
int n,c,l;
int cal(int p){
   if(p==0)return 0;
   else if(p<=10)return -c;
   else return (p-10)*(p-10);
}
int solve(int index,int lec){
      int &ret=dp[index][lec];
      if(ret<=(1<<30))return ret;
      if(lec==0){
          if(index==n)return ret=0;
          else return ret=(1<<30);
      }
      int sum=0;
      for(int i=index;i<n;i++){
          sum+=arr[i];
          if(sum>l)break;
          int tmp=solve(i+1,lec-1);
          if(tmp!=(1<<30))
          ret=min(ret,tmp+cal(l-sum));
      }
      if(ret>=(1<<30))return ret=(1<<30);
      return ret; 
}
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
      int Case=1;                         
      while(scanf("%d",&n)&&n){
            if(Case!=1)printf("\n");
            scanf("%d %d",&l,&c);
            for(int i=0;i<n;i++){
              scanf("%d",arr+i);
            }
            int lec=0;
            int sum=0;
            for(int i=0;i<n;i++){
               sum+=arr[i];
               if(sum>l){
                 sum=arr[i];
                 lec++;
               }
            }
            lec++;
             memset(dp,0x7f,sizeof(dp));
             printf("Case %d:\n",Case++);  
             printf("Minimum number of lectures: %d\n",lec);  
             printf("Total dissatisfaction index: %d\n",solve(0,lec)); 
            
      }

}