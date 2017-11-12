/**
*  Idea : all i  have that first student not posioned so earse all foods that 1st student had eat and then for other student calcualte 
*         The number of unsave foods and then if this person eat some food all of them 1st eat he won't be poisoned and the number of unsave 
*         - the total >= m so i can maybe i eat unpoisoned otherwise No
*         Happy solving :)
**/

#include <bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
#endif
      int n;
      scanf("%d",&n);
      set<string>st;
      string s;

      for(int i=0;i<n;i++){
         cin>>s;
         st.insert(s);
      }
      int k,m;
      scanf("%d %d",&k,&m);
      for(int i=0;i<m;i++){
         cin>>s ;
         st.erase(s);
      }
      vector<int>v;
      for(int i=0,f;i<k;i++){
         int cnt=0;
         scanf("%d",&f);
         for(int j=0;j<f;j++){
            cin>>s;
            if(st.count(s)==1){
             cnt++;
            }
         }
         v.push_back(cnt);
      }
      scanf("%d",&m);
      for(int i=0;i<k;i++){
        int u=v[i];
        if(!u){
          puts("YES");
        }else if(((int)st.size()-u) >= m){
            puts("MAYBE");
        }else 
           puts("NO");
      }



}