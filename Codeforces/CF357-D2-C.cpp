/*
*    Idea : Trivial problem But will give Tle if u use map or something like that
*          Process : make sequnce from 1 to n and if from i,j killed remove from sequence to avoid 
*                    Big Space Searching 
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=3*((int)1e5);
int arr[N];
set<int>s;
int main(){
   int n,m;
   scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++)s.insert(i);

   for(int i=1,a,b,x;i<=m;i++){
       scanf("%d %d %d",&a,&b,&x);
       set<int>::iterator itr=s.lower_bound(a);
       while(*itr<=b){
           if(*itr==x){
             ++itr;
           }else{
             arr[*itr]=x;
             s.erase(itr++);
           }
           if(itr==s.end())break;
       }
   }
   for(int i=1;i<=n;i++){
     printf("%d ",arr[i]);
   }
}
