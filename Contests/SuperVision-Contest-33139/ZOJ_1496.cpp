/*
*  Idea :  Really Greedy solution just try for each front and back cog if the difference to target less  than the previous then it's the answer :)
*
*/
#include <bits/stdc++.h>
using namespace std;
int front[4];
int back[10];
const double pi=3.14159;



int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
       int n,Case=1;
       scanf("%d",&n);
       while(n--){
          if(Case!=1)puts("");
          Case++;
          for(int i=0;i<3;i++){
            scanf("%d",&front[i]);
          }
          for(int i=0;i<9;i++){
            scanf("%d",back+i);
          }
          double dia,target;

          scanf("%lf %lf",&dia,&target);
          dia*=pi;
          double ans=0.0;
          int ansi=0,ansj=0;
          for(int i=0;i<3;i++){
             for(int j=0;j<9;j++){
                 double tmp=(double)front[i]/back[j]*dia;
                 if(fabs(ans-target) > fabs(tmp-target)){
                    ansi=i;
                    ansj=j;
                    ans=tmp;
                 }
             }
          }
          printf("A gear selection of %d/%d produces a gear size of %.3f.\n",front[ansi],back[ansj],ans);
       }
}