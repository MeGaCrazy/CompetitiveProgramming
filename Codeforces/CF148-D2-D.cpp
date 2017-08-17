/*
*    Idea :
*          we need to get max probablitiy to get White so need the element that the dragon choosen is black
*          so First we calculate the probablity to get white 
*          Second cal to get Black And Multibly it with Getting The Dragon the next of me will get Black not white :)
*          if the  probability to get black > 0 The game can continue There is two choice the white mouse jump
*          Or Black jump so calculate them and muliply with probablility of choosen black :)
*          Summary :
*            The Key it's we need to choose that black that can be drawn so Get Best Probablility of White EveryTime 
*            Queen Probabliltiy to Winning = (choose White) + (choose black * The Dragon choose black * (prob of Jump white  + black );
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1005;
double dp[N][N];
double solve(int w,int b){
      if(w<=0)return 0;
      if(b<=0)return 1;
      double &ret=dp[w][b];
      if(ret!=-1.0){
        return ret;
      }
      ret=(w*1.0)/(w+b);
      double black=(b*1.0)/(b+w);
      b--;
      black*=(b*1.0)/(b+w);
      b--;
      if(black>= (1e-9)){
        double w_jump=solve(w-1,b)*((w*1.0)/(w+b));
        double b_jump=solve(w,b-1)*((b*1.0)/(w+b));
        ret+=(black)*(w_jump+b_jump);
     }
     return ret;

}
int main(){
     int w,b;
     scanf("%d %d",&w,&b);
     for(int i=0;i<=w;i++){
        for(int j=0;j<=b;j++){
             dp[i][j]=-1.0;
        }
     }
     printf("%.9f",solve(w,b));
}