/*
*  target : get the minimum difference between max f(a,b) and min f (c,d);
*     sol : to make the difference decreace we need to decreace max sum or increace min sum
*           But u can't decreace the max sum coz any 2 subseqence will contain max element and second max one
*           but u we can get benefit from +ve (h) to increace min sum... to do  Just make min element in different sequence
*           All Probability :
*                    1- every Element in same Sequence 
*                    2- min element in single sequence and other element in that other One
*
*
*/


#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int arr[N],id[N];
bool cmp(int i,int j){
     return arr[i]<arr[j];
}


int main(){
      int n,h;
      scanf("%d %d",&n,&h);
      for(int i=1;i<=n;i++){
         scanf("%d",arr+i);
         id[i]=i;
      }
      sort(id+1,id+n+1,cmp);
      int sum=(arr[id[n]]+arr[id[n-1]])-(arr[id[1]]+arr[id[2]]);
      int mx=max(arr[id[n]]+arr[id[n-1]],arr[id[n]]+arr[id[1]]+h);
      int mn=min(arr[id[1]]+arr[id[2]]+h,arr[id[2]]+arr[id[3]]);
      if(sum<=(mx-mn)){
           printf("%d\n",sum);
           for(int i=1;i<=n;i++)printf("1 ");
           puts("");
      }else{
          printf("%d\n",mx-mn);
          for(int i=1;i<=n;i++){
             if(i==id[1])printf("2 ");
             else printf("1 ");
          }
          puts("");
      }
}