/*
*       d[n][j][k] means number of ways to place i buildings, where j is visible from the left and k from the right.
*       Now imagine you are placing buildings one by one from the smallest to the tallest, there are only three cases to consider:
*       1) You put it on the leftmost free position - it will be visible from left
*       2) You put it on the rightmost free position - it will be visible from right
*       3) You put it on one of the remaining n-2 positions - it won't be visible.
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
const int N=105,Mod=1000000007;
int dp[N][N][N];                 
class Skyscrapers {
public:
        int solve(int n,int l,int r){
           int &ret=dp[n][l][r];
           if(ret!=-1)return ret;
           ret=0;
           if(n==1)return ret=(l==1&&r==1);
           if(l<1||r<1)return ret=0;
           ret=(ret+solve(n-1,l-1,r)+solve(n-1,l,r-1)+((long long)(n-2)*solve(n-1,l,r))%Mod)%Mod;
           return ret=ret%Mod;
        }

	int buildingCount(int N, int leftSide, int rightSide) {
            memset(dp,-1,sizeof(dp));
            return solve(N,leftSide,rightSide);
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, bool hasAnswer, int p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2;
	cout << "]" << endl;
	Skyscrapers *obj;
	int answer;
	obj = new Skyscrapers();
	clock_t startTime = clock();
	answer = obj->buildingCount(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 2;
	p2 = 2;
	p3 = 2;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	p1 = 2;
	p2 = 1;
	p3 = 1;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 5;
	p1 = 3;
	p2 = 2;
	p3 = 18;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 12;
	p1 = 1;
	p2 = 1;
	p3 = 0;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 8;
	p1 = 3;
	p2 = 2;
	p3 = 4872;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, true, p3) && all_right;
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