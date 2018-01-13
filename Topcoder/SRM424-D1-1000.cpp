/**
    @Author: MeGaCrazy

    @Idea : First he want to calculate The Price "the distance between every tree numbered less than i"
            = i*X[i] - X[0...i-1]  But there's a problem u must know if X[j] others trees less than X in left or right 
             of X[i] to avoid negative problem so now to get the distance u want must follow this obviously formula
             Price X[i] = (# of left trees  )*X[i] - (cumlative Sum of left trees) + (cumlative sum of right trees) - (# of right trees )* X[i]
    Corner Case : Take Care if the position of tree = 0 due to using mod so add 1 for all positions
             Happy Solving :)

**/

#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
using namespace std;

const int Mod=1000000007;
const int MaxN=2e5+7;
long long X[MaxN];
long long cnt[MaxN];
long long dis[MaxN];
class ProductOfPrices {
public:
void update(long long a[],int idx,int value){
      while(idx < MaxN){
          a[idx] += value;
          idx += (idx & -idx);
      }
}
long long  Query(long long a[],int idx){
    long long ret=0;
    while(idx > 0){
       ret+=a[idx];
       idx -= (idx & -idx);
    }
  return ret;
}
long long Query(long long a[],int l,int r){
    return Query(a,r) - Query(a,l-1);
}

	int product(int N, int L, int X0, int A, int B) {
	    X[0]= X0 % L;
	   for(int i=1;i<N;i++){
	      X[i]=(X[i-1]*(long long)A+(long long)B)%L;
           }
           for(int i=0;i<N;i++){
              X[i]++;
           }
	   memset(cnt,0,sizeof(cnt));
	   memset(dis,0,sizeof(dis));
	  
	   update(cnt,X[0],1);
	   update(dis,X[0],X[0]);
	   long long ans=1;
	   for(int i=1;i<N;i++){
	         long long tmp = X[i] * (Query(cnt,1,X[i]-1)-Query(cnt,X[i]+1,L))
	                         - Query(dis,1,X[i]-1) + Query(dis,X[i]+1,L);
	         tmp %= Mod;
	         ans = (ans*tmp)%Mod;
                 update(cnt,X[i],1);
	         update(dis,X[i],X[i]);

	   }
	   return (int)ans;
	   
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, int p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << p4;
	cout << "]" << endl;
	ProductOfPrices *obj;
	int answer;
	obj = new ProductOfPrices();
	clock_t startTime = clock();
	answer = obj->product(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	} else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	} else if (hasAnswer) {
		cout << "Match :-)" << endl;
	} else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;
	
	int p0;
	int p1;
	int p2;
	int p3;
	int p4;
	int p5;
	
	{
	// ----- test 0 -----
	p0 = 5;
	p1 = 10;
	p2 = 3;
	p3 = 1;
	p4 = 1;
	p5 = 180;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 20;
	p2 = 5;
	p3 = 2;
	p4 = 3;
	p5 = 64;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 4;
	p1 = 21;
	p2 = 1;
	p3 = 7;
	p4 = 1;
	p5 = 3087;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 100;
	p2 = 4;
	p3 = 37;
	p4 = 11;
	p5 = 591860767;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5;
	p1 = 200000;
	p2 = 999999999;
	p3 = 123456789;
	p4 = 987654321;
	p5 = 499739175;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!