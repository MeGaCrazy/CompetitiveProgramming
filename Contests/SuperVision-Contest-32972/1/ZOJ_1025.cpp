/*
*      Idea: Just Sort according to length then weight  so now u don't have to care about comparing lengths anymore.
*            Then make LDS (Longest Decreasing Subsequence) The Answer is The length of LDS =D Cool :) 
*             Happy Solving :)
*/

#include <bits/stdc++.h>
using namespace std;
const int N=5005;
struct node{
   int l,w;
   bool operator <(node x)const{    
     if(l!=x.l)return l<x.l;
     return w < x.w;
   }
};
node arr[N];
int LDS[N];
int main(){
     int t;
     scanf("%d",&t);
     while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int> >v;
        for(int i=0,a,b;i<n;i++){
           scanf("%d %d",&arr[i].l,&arr[i].w);
        }
        sort(arr,arr+n);
        LDS[0]=arr[0].w;
        int ans=1;
        for(int i=1;i<n;i++){
             int l=0,r=ans;
             while(l!=r){      
                 int mid=(l+r)>>1;
                  if(LDS[mid]>arr[i].w)l=mid+1;
                  else r=mid;
             }
             if(l==ans)ans++;
             LDS[l]=arr[i].w;
        }
        printf("%d\n",ans); 
 }

}