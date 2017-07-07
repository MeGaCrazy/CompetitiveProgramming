/*
*  target : return if the segment intersect with rectangle or not
*  sol   : 1-check if the segment inside the rectangle 
           2-check if is parrale with any of trangle line and visa versa then check if he OnTheSegment True Got Solu :)
*          corner case : if point of line out side and point in side (i mean not parallel also intersect and not totally inside the rectangle )
*/


#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int> >line,rec;
#define x first
#define y second
bool isOnSegment(pair<int,int>i,pair<int,int>j,pair<int,int>p){
     if(min(i.x,j.x)<=p.x&&max(i.x,j.x)>=p.x&&
       min(i.y,j.y)<=p.y&&max(i.y,j.y)>=p.y
     )return true;

     return false;
}
int cross_prod(pair<int,int>i,pair<int,int>j,pair<int,int>p){
     return  (j.x-i.x)*(p.y-i.y)-(j.y-i.y)*(p.x-i.x);
}
bool ans;

bool solve(){
 // first check if line inside the rectangle
    if(line[0].x>=rec[0].x&&line[0].x<=rec[3].x&&
       line[1].x>=rec[0].x&&line[1].x<=rec[3].x&&
       line[0].y<=rec[0].y&&line[0].y>=rec[3].y&&
       line[1].y<=rec[0].y&&line[1].y>=rec[3].y
    )return true;
    // Line Intersect
    for(int i=0;i<4;i+=3){
       for(int j=1;j<=2;j++){
         // get all possible intersection 
         int d1,d2,d3,d4;
         d1=cross_prod(rec[i],rec[j],line[0]);
         d2=cross_prod(rec[i],rec[j],line[1]);
         d3=cross_prod(line[0],line[1],rec[i]);
         d4=cross_prod(line[0],line[1],rec[j]);
         if(d1*d2<0&&d3*d4<0){return true;}   
         else if(d1==0&&isOnSegment(rec[i],rec[j],line[0])){return true;}
         else if(d2==0&&isOnSegment(rec[i],rec[j],line[1])){return true;}
         else if(d3==0&&isOnSegment(line[0],line[1],rec[i])){return true;}
         else if(d4==0&&isOnSegment(line[0],line[1],rec[j])){return true;}
       }
    }
    return false;
}
int main(){
    int t;
//    freopen("in","r",stdin);
    scanf("%d",&t);
    while(t--){
        // clear
         line.clear();
         rec.clear();

        int line_x,line_y,line_xx,line_yy,rec_x,rec_y,rec_xx,rec_yy;
        scanf("%d %d %d %d %d %d %d %d",&line_x,&line_y,&line_xx,&line_yy,&rec_x,&rec_y,&rec_xx,&rec_yy);
        // get all side  points of rectanlge
        int Rec_x=min(rec_x,rec_xx);
        int Rec_y=max(rec_y,rec_yy);
        int Rec_xx=max(rec_x,rec_xx);
        int Rec_yy=min(rec_y,rec_yy);

        line.push_back(make_pair(line_x,line_y));
        line.push_back(make_pair(line_xx,line_yy));
        rec.push_back(make_pair(Rec_x,Rec_y));
        rec.push_back(make_pair(Rec_x,Rec_yy));
        rec.push_back(make_pair(Rec_xx,Rec_y));
        rec.push_back(make_pair(Rec_xx,Rec_yy));
        solve();
       printf(solve()==1?"T\n":"F\n");
     }
}

