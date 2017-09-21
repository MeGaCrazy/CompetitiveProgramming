/*
*   Idea : Just Nim Game piles is number of colums left and right Bad cell and above and down it
*
*
*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
       int n,m,x,y;
       scanf("%d %d %d %d",&n,&m,&x,&y);
       int ans=0;
       ans=x^y;
       ans^=n-x-1;
       ans^=m-y-1;
       if(ans)puts("Gretel");
       else puts("Hansel");
    }
}