#include <bits/stdc++.h>
using namespace std;
string orgin;
char str[50];
vector<pair<int, pair<vector<pair<int, int> >, int >  > >v,v2;
bool cmp(pair<int, pair<vector<pair<int, int> >, int >  > a, pair<int, pair<vector<pair<int, int> >, int >  >b) {
	int pen = a.second.second;
	int solved_a = 0;
	int solved_b = 0;
	int pen_a = 0;
	int pen_b = 0;
	for (int i = 0; i<(int)a.second.first.size(); i++) {
		solved_a += ((a.second.first[i].second >= 1) * 1);
		pen_a += (a.second.first[i].second + pen*(a.second.first[i].first-1));
	}
	for (int i = 0; i<(int)b.second.first.size(); i++) {
		solved_b += ((b.second.first[i].second >= 1) * 1);
		pen_b += (b.second.first[i].second + pen*(b.second.first[i].first-1));
	}
	if (solved_a > solved_b)return true;
	if(solved_a<solved_b)return false;
	if (pen_a < pen_b)return true;
	if(pen_a>pen_b)return false;
	if(a.first<b.first)return true;
	return false;
}
bool check(int mid){
		    for(int i=0;i<(int)v.size();i++){
		       v2[i].second.second=mid;
		    }
		    sort(v2.begin(),v2.end(),cmp);
		    string tmp="";
		    for(int i=0;i<(int)v.size();i++){
		        sprintf(str,"%d",v2[i].first);
		        tmp+=str;
		    }
		    return tmp==orgin;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
#endif
	int n, m;
	while (scanf("%d %d", &n, &m), (n || m)) {
		int a, b;
		v.clear();
		for (int i = 1; i <= n; i++) {
			vector<pair<int, int> >tmp;
			for (int j = 1; j <= m; j++) {
				scanf("%d/%s", &a, &str);
				if (str[0] == '-')b = 0;
				else sscanf(str, "%d", &b);
				if(b==0){
				 tmp.push_back(make_pair(0,0));
				}
				else tmp.push_back(make_pair(a, b));
	                 }
			v.push_back(make_pair(i,make_pair(tmp, 20)));
		}                 	
		sort(v.begin(), v.end(), cmp);
		v2=v;
               		
		orgin="";
		for(int i=0;i<(int)v.size();i++){
		    sprintf(str,"%d",v[i].first);
		    orgin+=str;
		}
		
		int l,r;
		l=1,r=20;
		while(l<r){
		    int mid=(l+r)>>1;
		    if(check(mid)){
		       r=mid;
		    }else{
		      l=mid+1;
		    }
	       }
	        printf("%d ",l);
		l=20,r=100005;
		while(l<r){
		    int mid=(l+r+1)>>1;
		    if(check(mid)){
		       l=mid;
		    }else{
		      r=mid-1;
		   }
	       }

	       if(r==100005){
	         puts("*");
	       }else{
	        printf("%d\n",r);
	       }
	       fprintf(stderr,"The Run Time is %d ms\n",(int)clock());
	}
}