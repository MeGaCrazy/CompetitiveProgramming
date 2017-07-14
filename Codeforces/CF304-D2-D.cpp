/*
*      target : get max sub-rectangle in contain point (x,y) and between (0,0) -> (n,m) and his center the closted to (x,y)
*         sol : First we Need to simplfiy the ratio a/b to calculate the side of rectangle efficently
*               Second get the max side by div n/his ratio ,m/his ratio now we get the min between them
*               coz if u get the bigger Sure wil be outof range yes will saticafiy the ratio But out of Range (n,m):)
*               (Third) Now to get the lower-left point we have to consider the condition must be The his center be the closted 
*                       to x,y 
*                       now u have 2 choice 
*                       make x1=x-a Or Try to shifting him by the difference unit between the center and x 
*                       Same as y But if difference <0 mean just make him at rectangle because we can't shifting under (0,0) :) OutOfRange :)
*                                                                      
*
*/


#include <bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    if(b==0){
     return a;
    }
    return gcd(b,a%b);
}
int main(){
    int n,m,x,y,a,b;
    scanf("%d %d %d %d %d %d",&n,&m,&x,&y,&a,&b);
    int cof=gcd(a,b);
    a/=cof; b/=cof;
    int dis=min(n/a,m/b);
    a*=dis,b*=dis;
    int x1=min(n-a,max(0,x-(a+1)/2));
    int y2=min(m-b,max(0,y-(b+1)/2));
    printf("%d %d %d %d\n",x1,y2,x1+a,y2+b);
}