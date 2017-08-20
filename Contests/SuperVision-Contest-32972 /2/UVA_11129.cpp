/*
*       Idea:
*            who is the number that make the arithmetic progression . that the number with same type like even  or odd 
*            okey now the process take the even in front of array then the odd in back 
*            if we have array like that 0 1 2 3 4 5 => 0 2 4   1 3 5
*                                          next step   0 4 2   1 5 3
*                                                     now there is no arithmetic progression in this sequnce
*            Happy Solving :) 
*/

#include <bits/stdc++.h>
using namespace std;
const int N=12345;
int arr[N],start[N];
void solve(int l,int r){
   if(l==r)return;
   int j=l;
   for(int i=l;i<=r;i+=2){
     arr[j++]=start[i];
   }
   for(int i=l+1;i<=r;i+=2){
     arr[j++]=start[i];
   }
   for(int i=l;i<=r;i++){
       start[i]=arr[i];
   }
   int mid=(l+r)>>1;
   solve(l,mid);
   solve(mid+1,r);
}
int main(){
    int n;
    while(scanf("%d",&n),n){
        for(int i=0;i<n;i++)start[i]=i;
         solve(0,n-1);
         printf("%d: ",n);
         for(int i=0;i<n;i++){
            printf(i==0?"%d":" %d",arr[i]);
         }
         puts("");
    }

}


