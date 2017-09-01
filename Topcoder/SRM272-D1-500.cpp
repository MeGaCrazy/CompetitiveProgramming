/*
*    idea : hot to get he state for siting a repersentitve A is Current chair * ( remain A )
*            there is There 3 choice put A or Put B or make him Empty 
*
*
*/
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
#include <string.h>
#include <string>

using namespace std;
const int N=55;
long long  dp[N][N][6][6][4];
int d; 
int ch;

class RoundTable {
public:
       long long solve(int index,int dis,int a,int b,int last){
               if(a==0&&b==0)return 1;
               if(index==0)return 0;
               long long &ret=dp[index][dis][a][b][last];
               if(ret!=-1)return ret;
               ret=0;
               ret+=solve(index-1,max(0,dis-1),a,b,last);
               if(a>0&&(last==0||dis==0))ret+=a*solve(index-1,d-1,a-1,b,0);
               if(b>0&&(last==1||dis==0)&&index>=d)ret+=b*solve(index-1,d-1,a,b-1,1);
               return ret;
        }
	long long arrangements(int a, int b, int chairs, int minDistance) {
		memset(dp,-1,sizeof(dp));
		d=minDistance;
		long long ret=solve(chairs-1,d-1,a-1,b,0);
		return chairs*ret;
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, bool hasAnswer, long long p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	RoundTable *obj;
	long long answer;
	obj = new RoundTable();
	clock_t startTime = clock();
	answer = obj->arrangements(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p4 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p4;
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
	long long p4;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1;
	p2 = 10;
	p3 = 1;
	p4 = 90ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2 = 10;
	p3 = 2;
	p4 = 70ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 1;
	p1 = 2;
	p2 = 7;
	p3 = 3;
	p4 = 14ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 5;
	p1 = 3;
	p2 = 7;
	p3 = 1;
	p4 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 5;
	p1 = 3;
	p2 = 11;
	p3 = 3;
	p4 = 0ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 2;
	p1 = 1;
	p2 = 3;
	p3 = 1;
	p4 = 6ll;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = 2;
	p1 = 3;
	p2 = 20;
	p3 = 4;
	p4 = 180000ll;
	all_right = KawigiEdit_RunTest(6, p0, p1, p2, p3, true, p4) && all_right;
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
