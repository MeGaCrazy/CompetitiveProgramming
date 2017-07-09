/*
*    target : evalate the grammer
*     sol   : use the recursive-descent parser
*/

#include <bits/stdc++.h>
using namespace std;
const int N=255;
char str[N],*ps;
bool flag;
int get_num(){
   int num=0;
   if(isdigit(*ps)){
       while(isdigit(*ps)){
           num=num*10+(*ps++ -'0');
       }
       return num;
   }else {
     return -1;
   }
}
int expression();
int factor();
int component();


int factor(){
    int num=get_num();
    if(num!=-1){
        return num;
    }
    else if(*ps=='('){
       ps++;
       int n=expression();
       if(*ps==')')ps++;
       else flag=0;
       return n;
    }
    else{
      flag=0;
      return -1;
    }
}
int component(){
     int n=factor();
     if(*ps=='*'){
        ps++;
        n*=component();
     }
     return n;
}
int expression(){
      int a=component();
      if(*ps=='+'){
         ps++;
         a+=expression();
      }
      return a;
}


int main(){
    int n;
    scanf("%d",&n);
    while(n--){
       scanf("%s",ps=str);
       flag=true;
       int ans=expression();
       if(flag&&ans!=-1&&*ps==NULL){
         printf("%d\n",ans);
       }else {
         printf("ERROR\n");
       }
    
    }
}