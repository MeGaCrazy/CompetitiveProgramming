/*
*      First all u need to manage that the median how to get it 
*      median in all elements before him is less than him and after him surely bigger than him (Seq is sorted) :)
*      to manage that :
*             1- need to have 2 prirority_queue one save that all i have before me is less than me 
*             2- and the second to manage to store element when the index is even and take also when
*             he had element less than me .. take a look 
*                            median
*               first_priroty      second_priority
*                all<=median         all >median
*                
*/

#include <bits/stdc++.h>
using namespace std;
const int Mod=1000000007;



int main(){
   int t;
   scanf("%d",&t);
   while(t--){
       int a,b,c,n;
       scanf("%d %d %d %d",&a,&b,&c,&n);
       priority_queue<int>q;
       priority_queue<int,vector<int>,greater<int> >q2;
       q.push(1);
       long long ans=1;
       for(int i=2;i<=n;i++){
          int tmp=((1ll*a*q.top())%Mod+(1ll*b*(i))%Mod+((c)%Mod))%Mod; 
//          cerr<<"Mid "<<q.top()<<" => "<<"nw Element "<<tmp<<endl;
          if(i&1){
             q.push(tmp);
          }else{
            q2.push(tmp);
          }
          if(!q2.empty()&&q.top()>q2.top()){
             int u=q.top();
             int v=q2.top();
             q.pop();
             q2.pop();
             q.push(v);
             q2.push(u);
          }
          ans+=tmp; 
       }
       printf("%lld\n",ans);
       fprintf(stderr,"The Test end in %d ms\n",(int)clock());
   }

}


/*
#include <bits/stdc++.h>
using namespace std; 
const int Mod=1000000007;




int main(){
       int t,a,b,c,n;
       scanf("%d",&t);
       while(t--){
           scanf("%d %d %d %d",&a,&b,&c,&n);
           long long ans=1;
           vector<int>arr;
           arr.push_back(1);
           if(!a&&!b&&!c){puts("1");continue;}
           for(int i=1;i<n;i++){
              int mid=i>>1;
              if((i&1)==0)mid--;
//              cerr<<(i-1)<<" The Mid is "<<mid<<endl;
              int tmp=((1ll*a*arr[mid])%Mod+(1ll*b*(i+1))%Mod+((c)%Mod))%Mod;
              vector<int>::iterator itr=lower_bound(arr.begin(),arr.end(),tmp);
              arr.insert(itr,tmp);
              ans+=tmp;
           }
           printf("%lld\n",ans);
           fprintf(stderr,"The Run Time is %d ms\n",(int)clock());
       }
}
*/
