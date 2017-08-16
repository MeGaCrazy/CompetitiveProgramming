/*
*         The Idea :
*                  Always make s(SizeOfSet) = (int)1e6 then 
*                  1-First Step
*                  to get element y take the symmetric of element of x But make sure that not exit in x
*                  The symmetric of i  = ((s)-i+1) :) and vice versa 
*                  2- Second Step
*                      if i and his symmetric already in X Just take any (j) and his symmetric that don't belong to x
*                      For illustration take this sample :)
*                          if X ={1,1000000} Then the Sum of Formula of X is =(1000000-1)+(1000000-1000000)=999999
*                          take any i and his symmetric don't belong to x like
*                          i=2 his symmetric = 999999 Then Sum of Forumla of Y is=(1000000-2)+(1000000-999999)=999999
*                          Happy Solving :)    
*
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
bool vis[N];
int main(){
    int n;
    scanf("%d",&n);
    int sum=0;
    for(int i=1,a;i<=n;i++){
       scanf("%d",&a);
       vis[a]=1;
    }
    vector<int>ans;
    int cnt=0;
    for(int i=1;i<=N/2;i++){
        if(vis[i]){
            if(!vis[N-i+1]){
               ans.push_back(N-i+1);
               vis[N-i+1]=1;
            }else{
              cnt++;
            }
        }else if(vis[N-i+1]){
            vis[i]=1;
            ans.push_back(i);
        }
    }
    for(int i=1;cnt&&i<=N/2;i++){
         if(!vis[N-i+1]&&!vis[i]&&cnt){
            cnt--;
            ans.push_back(i);
            ans.push_back(N-i+1);
         }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
      printf("%d ",ans[i]);
    }
}       
