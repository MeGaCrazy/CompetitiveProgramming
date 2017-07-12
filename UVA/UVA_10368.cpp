/*
*  target : determine whose win
*  sol    : we have 3 options
*           1- a%b==0 then the currnet player win
*           2- a/b >1 he also will win coz he said that they play prefectly then they know (b,a%b) or (a%b,b) so he win too..
*           
*
*/

#include <bits/stdc++.h>
using namespace std;
int main(){
  long long a,b;
  while(scanf("%lld %lld",&a,&b),(a||b)){
       bool flag=true;
       if(a<b)swap(a,b);
       while(b){
           if(a%b==0||a/b>1){
              break;
           }
           a-=b;
           swap(a,b);
           flag=!flag;
       }
       printf("%s wins\n",flag==1?"Stan":"Ollie");
  }

}