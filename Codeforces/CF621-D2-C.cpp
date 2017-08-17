/*
*    Idea : 
*          1- to know how many divisble of p just divide the number by p  normal :)
*          2- then to know probability of numbers between two interval can make me win 1000 dollar
*             (number of divisable number)/(all number)
*          3- just iterate for every one and his neighbore we can do the opposite and opposite what we did to get the answer how :
*             get how many number will not divible for i and j and multiply by each other now we get the probability not get diviable in total
*             and if reverse again i mean (1- this probability Get The answer ) 
*             Happy Solving :)
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=123456;
int l[N],r[N],p;
double solve(int st,int en){
       return ((en/p)-((st-1)/p))/double(en-st+1);
}
int main(){
    int n;
    scanf("%d %d",&n,&p);
    for(int i=1;i<=n;i++){
      scanf("%d %d",l+i,r+i);
    }
    double ans=0;
    for(int i=1;i<=n;i++){
      double p1=solve(l[i],r[i]),p2=solve(l[i%n+1],r[i%n+1]);
      ans+=(1-(1-p1)*(1-p2))*2000;
    }
    printf("%.10f",ans);
}