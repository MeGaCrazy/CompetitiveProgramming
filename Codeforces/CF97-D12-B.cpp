/**
*   @Author : MeGaCrazy
*   @InitTime : Tue Feb 27 18:25:16 2018
*   @Idea :  as in tutorial 
*
*
*
*
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
using namespace std;
set<pair<int,int> >ans;
vector<pair<int,int> >v;
void solve(int l,int r){
    if(l+1>=r)return;
    int mid=(l+r)>>1;
    int x=v[mid].first;
    for(int i=l;i<r;i++)ans.insert(make_pair(x,v[i].second));
    solve(l,mid);
    solve(mid,r);
}
int main(){
#ifndef ONLINE_JUDGE
   freopen("in","r",stdin);
   //freopen("out","w",stdout);
#endif
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
       int x,y;
       scanf("%d %d",&x,&y);
       v.push_back(make_pair(x,y));
    }


    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)ans.insert(make_pair(v[i].first,v[i].second));
    solve(0,v.size());
    printf("%d\n",ans.size());
    for(pair<int,int>s:ans){
       printf("%d %d\n",s.first,s.second);
    }


}