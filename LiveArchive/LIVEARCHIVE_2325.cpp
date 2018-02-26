/**
*  idea :  it's observation the odd and even idexces  if we look at this impossile sample : 1|0|1|0|1|0 
*                                                                                      idx  0|1|2|3|4|5
*          u will observe that  for onces all indeces are even so any trying to make flipping  not effect 
*          But look more if the length if array with Odd : 1 0 1 0 1  Onces have even indces but can solve
*                                                          0 1 2 3 4 
*          one shiffting 11010 one flip 01110 :) So The if The length Odd alaways theres a answer :)
*          And Otherwise must  for Onces  number of Odd = even || Odd=even-1 || odd=even+1 that make sense 
*          for example : 1101   flip first three 0111 
*                        1234
* 
*         Happy Solving :)
**/


#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
        int t;
        scanf("%d",&t);
        while(t--){
          int n,ev=0,od=0;
          scanf("%d",&n);
          for(int i=0,a;i<n;i++){
            scanf("%d",&a);
            if(a==1){
               if(i&1)od++;
               else ev++;
            }
          }
          if((n&1)==1||ev==od||od==ev-1||od==ev+1){
               puts("YES");
            }
            else puts("NO");
        }


}