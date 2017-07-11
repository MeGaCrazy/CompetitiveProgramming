/*
*   target: get the valid postions qs that make sequence b in a by rearranging  elements
*    sol  :1- count the number of every elements in b that repeated how many times
*          2- try all postions from 1 to p and try the sequence that u generated now But..
*          3-The Checks if num of number a in generated sequence as in b cnt++ if he less than him just cnt --;
*          4-in way to generate sequence if num of sequnce Be Greater than the number of Orginial m
*          5-just simply remove the first and check if now is equal to the ogrinial cnt++;
*          every time check if m reach Bnums if yes first position of sequence is the answer Coz he said by rearraning
*          so we don't care for positions we just need the begining of the sequence :) enjoy
*    Summary: in the sequence the subsequence can be valid too if we remove the first :) 
*/


#include <bits/stdc++.h>
using namespace std;
const int N=223456;
int a[N],b[N],Bnum;
map<int,int>B;


int main(){

   int n,m,p;
   scanf("%d %d %d",&n,&m,&p);
   for(int i=1;i<=n;i++)scanf("%d",a+i);
   for(int i=1;i<=m;i++){
       scanf("%d",b+i);
       if(B[b[i]]==0)Bnum++;
       B[b[i]]++;
   }
   vector<int>ans;
   for(int i=1;i<=p;i++){
      queue<int>q;
      map<int,int>mp;
      int cnt=0;
      for(int j=i;j<=n;j+=p){
         q.push(j);
         mp[a[j]]++;
         if(mp[a[j]]==B[a[j]])cnt++;
         else if(mp[a[j]]==B[a[j]]+1)cnt--;
         if(q.size()>m){
             int x=q.front();q.pop();
             if(mp[a[x]]==B[a[x]])cnt--;
               mp[a[x]]--;
             if(mp[a[x]]==B[a[x]])cnt++;
         }
         if(cnt==Bnum)ans.push_back(q.front());
      }
   }
   sort(ans.begin(),ans.end());
   printf("%d\n",ans.size());
   for(int i=0;i<(int)ans.size();i++){
        printf(i==0?"%d":" %d",ans[i]);
   }
}
