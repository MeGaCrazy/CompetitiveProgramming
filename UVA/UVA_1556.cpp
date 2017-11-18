/**
*  Idea : Just Split the path and  for every path the store it's child and Use Dfs to print the output in formatted way :)
*
*
*
**/


#include <bits/stdc++.h>
using namespace std;
map<string,set<string> >mp;
set<string>first;
void modify(string &s){
    string sub="";
    string cut="";
    int i=0;
    for(;i<s.size();i++){
       if(s[i]=='\\'){
          i++;
          break;
       }
       sub+=s[i];
    }
    first.insert(sub);
    for(;i<(int)s.size();i++){
        if(s[i]!='\\'){
           cut+=s[i];
        }
        if(s[i]=='\\'||s.size()==i+1){
       //  cerr<<sub<<" " << cut<<endl;
           mp[sub].insert(cut);
           sub+=s[i];
           sub+=cut;
           cut="";
        }
    }

}
void dfs(string s,int dep){
     if(!dep){
         for(string x : first){
            cout<<x<<endl;
            for(auto y : mp[x]){
                dfs(x+"\\"+y,dep+1);
            }
         }
     }else{
        for(int i=0;i<(int)dep;i++){
         printf(" ");
        }
        string out="";
        int idx=0;
        for(int i=s.size()-1;i>=0;i--){
           if(s[i]=='\\'){
             break;
           }
           out+=s[i];
        }
        for(int i=out.size()-1;i>=0;i--){
          printf("%c",out[i]);
        }
        cout<<endl;
        for(auto y : mp[s]){
               dfs(s+"\\"+y,dep+1);
        }
     }
}

int main(){
#ifndef ONLINE_JUDGE
       freopen("in","r",stdin);
       freopen("out","w",stdout);
#endif
      int n;
      while(scanf("%d",&n)==1){
          mp.clear();
          first.clear();
          string s;
         for(int i=0;i<n;i++){
            cin>>s;
            modify(s);
         }
         dfs("",0);
         puts("");
      }
}
