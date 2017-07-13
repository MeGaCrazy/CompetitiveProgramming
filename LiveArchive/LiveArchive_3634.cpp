#include <bits/stdc++.h>
using namespace std;
map<set<int>,int>mpst;
map<int,set<int> >mpts;

int get_index(set<int>s){
   
   int &a=mpst[s];
   if(a==0){
     a=(int)mpst.size();
   }
   mpts[a]=s;
   return a;
}
int main(){
#ifndef ONLINE_JUDGE
         freopen("in","r",stdin);
#endif                           
       int t,n;
       scanf("%d",&t);
       char str[50]={};
       while(t--){
           scanf("%d",&n);
           stack<int>s;
           while(n--){
              scanf("%s",str);
              if(!strcmp(str,"PUSH")){
                 s.push(get_index(set<int>()));
              }else if(!strcmp(str,"DUP")){
                 s.push(s.top());
              }else if(!strcmp(str,"UNION")){
                 int a=s.top();s.pop();
                 int b=s.top();s.pop();
                 set<int> &aa=mpts[a],&bb=mpts[b],c;
                 set_union(aa.begin(),aa.end(),bb.begin(),bb.end(),inserter(c,c.begin()));
                 s.push(get_index(c));
              }else if(!strcmp(str,"INTERSECT")){
                 int a=s.top();s.pop();
                 int b=s.top();s.pop();
                 set<int> &aa=mpts[a],&bb=mpts[b],c;
                 set_intersection(aa.begin(),aa.end(),bb.begin(),bb.end(),inserter(c,c.begin()));
                 s.push(get_index(c));
              }else if(!strcmp(str,"ADD")){
                int a=s.top();s.pop();
                int b=s.top();s.pop();
                set<int>bb=mpts[b];
                bb.insert(a);
                s.push(get_index(bb));
              }                  
             printf("%d\n",(int)mpts[(int)s.top()].size());
           }
           puts("***");
       }
}
