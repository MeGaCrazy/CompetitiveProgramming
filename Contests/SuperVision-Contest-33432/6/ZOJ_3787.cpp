//#include <bits/stdc++.h>
/*
* Idea : Just tranfer The time to seconds and sorted By time then by id 
*        Just simulate the process :)
*
*       Happy Solving :)
*/
#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
const int N=20005;
pair<int,int>arr[N];
int main(){
//#ifndef ONLINE_JUDGE
//        freopen("in","r",stdin);
  //      freopen("out","w",stdout);
//#endif
       int t,n,l;
       scanf("%d",&t);
       while(t--){
          scanf("%d %d",&n,&l);
          for(int i=1,h,m,s;i<=n;i++){
                 scanf("%d:%d:%d",&h,&m,&s);
                 arr[i].first=(h*60*60)+(m*60)+(s);
                 arr[i].second=i;
          } 
         
          sort(arr+1,arr+n+1);
          vector<int>ans;
          ans.push_back(arr[1].second);
          int st=arr[1].first+l;
          for(int i=2;i<=n;i++){
             if(st >arr[i].first)continue;
             else{
               st=arr[i].first+l;
               ans.push_back(arr[i].second);
             }
          }
          sort(ans.begin(),ans.end());
          printf("%d\n",ans.size());
          for(int i=0;i<(int)ans.size();i++){
            printf(i==0? "%d":" %d",ans[i]);
          }
          puts("");
       }

}