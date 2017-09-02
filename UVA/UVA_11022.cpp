/*
*   Idea : Cute Nest Range problem Just make nested like Cutting Sticks problem and then 
*          if we in Range (l,r)   tcheck if there is 1-(r-l+1) consective  number are similar if there exist minimize so 
*          The Ordinary Thing if we have (l,r)range the ans is (r-l+1) But we make him if there is exist NumberOfSimilarConsectiveSubString consective equal we make that
*          range (l,r) = range (l,l+NumberOfSimilarConsectiveSubString)
*          Happy Solving :)
*/

#include <bits/stdc++.h>
using namespace std;
const int N=88;
int dp[N][N];
char s[N];

int solve(int l,int r){
       if(l==r)return 1;
       int &ret=dp[l][r];
       if(ret!=-1)return ret;
       ret=(int)1e9;
       for(int i=l;i<r;i++){
         ret=min(ret,solve(l,i)+solve(i+1,r));
       }
       int len=(r-l+1);
       for(int i=1,k,j;i<=len;i++){
          if(len%i==0){
             for(k=l,j=0;k<=r;k++){
                if(s[k]!=s[l+j])break;
                j++;
                if(j>=i)j=0;
             }
             if(k==r+1&&r!=(i+l-1)){
                ret=min(ret,solve(l,i+l-1));
             }
          }
       }
      return ret;
}
int main(){
      while(scanf("%s",&s),strcmp(s,"*")!=0){
         memset(dp,-1,sizeof(dp));
         int n;
         n=strlen(s);
         printf("%d\n",solve(0,n-1));
      }


}
