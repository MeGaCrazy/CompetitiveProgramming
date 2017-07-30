/*
*    Just a simlate of what he said
*    loop from first element bigger than given and check
*    if his sum of  prime factoris equal orginial digit
*
*/

#include <bits/stdc++.h>
using namespace std;
int get(int n){
   char s[12]={};
   int sum=0;
   sprintf(s,"%d",n);
   for(int i=0;i<(int)strlen(s);i++){
      sum+=(s[i]-'0');
   }
   return sum;
}
bool solve(int n){
    int a=get(n);
    int b=0;
    int ans=n;
    bool flag=1;
    for(int i=2;i<=(int)sqrt(n);i++){
       if(n%i==0){
         int cnt=0;
         while(n%i==0){
           cnt++;
           n/=i;
         }
         b+=cnt*get(i);
         flag=0;
       }
    }
    if(n!=1){
      b+=get(n);
    }
    if(a==b&&flag==0){
      printf("%d\n",ans);
       return 1;
    }
   return 0;

}


int main(){
#ifndef ONLINE_JUDGE
        freopen("in.txt","r",stdin);
#endif
       int t;
       scanf("%d",&t);
       while(t--){
          int n;
          scanf("%d",&n);
          for(int i=n+1;;i++){
              if(solve(i)==1)break;
          }
       }


}