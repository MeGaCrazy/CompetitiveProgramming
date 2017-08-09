/*
*         let's explain :) 
*         First we can observe that after some increace some element and decrease some elements will found the answer
*         Let Stop For a minute here to reduce the number of decreasing and increasing we need 
*         to found the maxnumber the we can increase to and get minnumber we can decreace to reduce the number of operations and get the 
*         Optimal Answer get difference Between maxnumber(that increasing) and minimumNumber(that decearsing) ..
*
*/

#include <bits/stdc++.h>
using namespace std;
const int N=500005  ;
int arr[N];
int main(){
     int n,k;
     scanf("%d %d",&n,&k);
     long long sum=0;
     for(int i=1;i<=n;i++){
          scanf("%d",arr+i);
          sum+=arr[i];
     }
     sort(arr+1,arr+1+n);
     int l1=(sum)/n,r1=(sum+(n-1))/n;
     int l=0,r=l1;    
     int ansl=0,ansr=0;
     while(l<=r){
        long long cnt=0;
        int mid=(l+r)>>1;
        for(int i=1;i<=n;i++){
          if(arr[i]<=mid)cnt+=(mid-arr[i]);
        }
        if(cnt<=k)ansl=mid,l=mid+1;
        else r=mid-1;
     }
     l=r1,r=1e9;
     while(l<=r){
        long long cnt=0;
        int mid=(l+r)>>1;
        for(int i=1;i<=n;i++){
          if(arr[i]>mid)cnt+=(arr[i]-mid);
        }
        if(cnt<=k)ansr=mid,r=mid-1;
        else l=mid+1;
     }
     printf("%d",ansr-ansl);
}

/*
#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int arr[N];
int n, k;
void down(int p) {
	for (int j = p; j <= ((n) / 2); j++) {
		int np = j << 1;
		int left = np, right = np + 1;
		if (!left || !right)break;
		int i = left;
		if (arr[right]<arr[left])i = right;
		if (!arr[right])i = left;
		if (!arr[left])i = right;
		if (!arr[left] && !arr[right])break;
		if (arr[j]>arr[i])swap(arr[j], arr[i]);
		else { break; }
	}
}
void up(int p) {
	if (arr[n]<arr[n - 1])swap(arr[n], arr[n - 1]);
	for (int j = p; j >= 3;) {
		int left, right;
		int np = ((j + 1) / 2);
		if (np & 1)
			left = j, right = j - 1;
		else
			left = j, right = j + 1;
		if (!left || !right)break;
		int i = left;
		if (arr[right]<arr[left])i = right;
		if (!arr[right])i = left;
		if (!arr[left])i = right;
		if (!arr[left] && !arr[right])break;
		if (arr[np]>arr[i])swap(arr[np], arr[i]);
		else break;
		j = np;
	}


}
int main() {
	freopen("in", "r", stdin);
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", arr + i);
	}
	sort(arr + 1, arr + 1 + n);
	int ans = arr[n]-arr[1];
	cerr<<arr[n]<<" "<<arr[1]<<endl;
	while (k--) {
		cerr << "hoi ";
		for (int i = 1; i <= n; i++) {
			cerr << " " << arr[i];
		}
		cerr << endl;
		if (arr[1] == arr[n]) { ans = 0; break; }
		if (arr[1] + 1 == arr[n]) { ans = 1; break; }
		arr[1]++;
		arr[n]--;
		down(1);
		up(n);
		
		cerr << "after :";
		for (int i = 1; i <= n; i++) {
			cerr << " " << arr[i];
		}
		cerr << endl;
		ans = arr[n] - arr[1];
		if (ans == 0)break;
	}
	fprintf(stderr,"time is %d",(int)clock());
	printf("%d", ans);

}

*/