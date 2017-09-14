/*
*   Idea : There is two condition if the required index is <= k then print it :)
*          else array that take how many number in range x,y and another array to tell it's begin 
*
*
*         Happy Solving :)
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=50005;
int arr[N],arr2[N],st[N],sum[N];

int main(){
#ifndef ONLINE_JUDGE
//        freopen("in","r",stdin);
  //      freopen("out","w",stdout);
#endif
      int t,Case=1;
      scanf("%d",&t);
      while(t--){
          int n,k,q;
          printf("Case %d:\n",Case++);
          scanf("%d %d %d",&n,&k,&q);
          for(int i=1;i<=k;i++){
            scanf("%d",arr+i);
            arr2[i]=arr[i];
          }
          sort(arr+1,arr+1+k);
         // vector<pair<int,pair<int,int> > > v;
          arr[0]=0,arr[k+1]=n+1;
          int index=1;
          sum[0]=0;
          for(int i=1;i<=k+1;i++){
               int l=arr[i-1]+1,r=arr[i]-1;
               if(l<=r){
                  sum[index]=sum[index-1]+(r-l+1);
                  st[index]=l;
                  index++;
               }
          }
          
          while(q--){
             int a;
             scanf("%d",&a);
             if(a <= k){
               printf("%d\n",arr2[a]);
             }else{
               a-=k;
               int pos=lower_bound(sum,sum+index,a)-sum;
               printf("%d\n",st[pos]+(a-sum[pos-1]-1));
             }

          }
      
      }

}