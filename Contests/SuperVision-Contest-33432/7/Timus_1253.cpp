/*
*   Idea : Problem trivial But The Understanding the Text more Tricky :)
*          all he want is print first line so let's define the line : we said it's new line if it last with (#)                                                              
*          so as we saw in first sample : he treat the first two line as i line (Why) coz first line is not end with # :)
*          Corner Cases : u must take care if we in cycle and if u repair a line u should repaired it again just return it 
*
*          Happy Solving :)
*/
#include <bits/stdc++.h>
using namespace std;
const int N=15;
string str[N];
int sz[N];
bool visit[N],cyc[N];
bool solve(int idx,string &ret){
        visit[idx]=cyc[idx]=1;
        for(int i=0;i<(int)str[idx].size();i++){
               if(str[idx][i]=='*'){
                  int to=(str[idx][++i]-'0');
                  if(cyc[to])return 0;
                  if(!visit[to]){
                     string tmp="";
                     if(!solve(to,tmp))return 0;
                     str[to]=tmp;
                  }
                 ret+=str[to];
                 sz[idx]+=sz[to];
               }else{
                ret+=str[idx][i];
               }
        }
        cyc[idx]=0;
        return 1;
}
int main(){
       int t;
       scanf("%d",&t);
       string s;
       int n=1;
       cin.ignore();
       while(getline(cin,s)){
           int last=n;
           for(int i=0;i<(int)s.size();i++){
               if(s[i]=='#')n++;
               else{
                    str[n]+=s[i];
                    if(s[i]=='*'){
                       str[n]+=s[++i];
                    }
                    else sz[n]++;
                  }
           }
           if(s[s.size()-1]!='#')sz[n]++;
           if(last==n)str[n]+='\n';
       }
       memset(visit,0,sizeof(visit));
       memset(cyc,0,sizeof(cyc));
       string ret="";
       cout<<((solve(1,ret)==1&&sz[1]<=(int)1e6)?ret:"#")<<endl;
}