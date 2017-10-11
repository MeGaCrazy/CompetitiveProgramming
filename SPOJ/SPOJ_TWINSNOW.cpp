/*
*  Idea : just sort lengths of arms in every snowflake  and then sort all of them 
*
*/

#include <bits/stdc++.h>
using namespace std;
struct snow{
  int x[6];
};
bool operator <(const snow &a,const snow &b){
       return lexicographical_compare(a.x,a.x+6,b.x,b.x+6);
}
bool operator ==(const snow &a,const snow &b){
        return equal(a.x,a.x+6,b.x);
}


int main(){
#ifndef ONLINE_JUDGE
        freopen("in","r",stdin);
#endif
       int n;
       scanf("%d",&n);
       snow a;
       vector<snow>v;
       for(int i=0;i<n;i++){
          for(int j=0,y;j<6;j++){
             scanf("%d",&y);
             a.x[j]=y;
          }
          sort(a.x,a.x+6);
          v.push_back(a);
       }
       sort(v.begin(),v.end());
       bool f=0;

       for(int i=0;i<(int)v.size()-1;i++){
           if(v[i]==v[i+1]){
              printf("Twin snowflakes found.\n");
              return  0;
           }
       }
       printf("No two snowflakes are alike.\n");
}

