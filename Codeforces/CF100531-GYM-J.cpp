/**
*   @Author : MeGaCrazy
*   @InitTime : Wed Aug 15 05:47:27 2018
*   @Idea :   1- (ignore the our speed at first) First Calculate the end point with the winding changes
*             2- calculate the distance between the end points and final points
*             3- Check whether can achieve it using maxium speed after k seconds
*             4- if yes get the vector from end point and final point divide by k round  call it mid
*             5- for k time add winding changes and add midx and midy for it and print that's it
*
*  Happy Solving :)
**/
#include <bits/stdc++.h>
const int N=1e4+7;
int t[N],x[N],y[N];
using namespace std;
int main(){
   freopen("joy.in","r",stdin);
   freopen("joy.out","w",stdout);
    int sx,sy,fx,fy;
    scanf("%d %d %d %d",&sx,&sy,&fx,&fy);
    int n,k,vmax;
    scanf("%d %d %d",&n,&k,&vmax);
    for(int i=0;i<n;i++){
    	scanf("%d %d %d",&t[i],&x[i],&y[i]);
    }
    long long Sx=sx,Sy=sy;
    for(int i=0,j=0;i<k;i++){
    	if(j<n-1&&t[j+1]==i)j++;
    	Sx+=x[j];
    	Sy+=y[j];
    }
    long long disx=fx-Sx,disy=fy-Sy;
    if(disx*disx+disy*disy <= (long long)vmax*vmax*k*k){
    	printf("Yes\n");
    	double X=sx,Y=sy;
    	double midx=(double)disx/k*1.0,midy=(double)disy/k*1.0;
    	for(int i=0,j=0;i<k;i++){
    	     if(j<n-1&&t[j+1]==i)j++;
    	     X+=x[j]+midx;
    	     Y+=y[j]+midy;
    	     printf("%.12f %.12f\n",X,Y);
    	}	

    }else{
    	printf("No");
    }



}