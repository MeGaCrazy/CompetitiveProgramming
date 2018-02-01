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

using namespace std;


class AlternateColors {
public:
	string solve(int i) {
		if (i == 1) {
			return "RED";
		}
		else if (i == 2) {
			return "GREEN";
		}
		else {
			return "BLUE";
		}

	}
	string solve1(int i){
		if (i == 0) {
			return "RED";
		}
		else if (i == 1) {
			return "GREEN";
		}
		else {
			return "BLUE";
		}

	} 	
	string getColor(long long r, long long g, long long b, long long k) {
		long long a[3];
		a[0] = r;
		a[1] = g;
		a[2] = b;
		long long x = min(a[0], min(a[1], a[2]));
		if (x * 3 >= k) {
			return solve(k % 3);
		}
		for (int i = 0; i<3; i++) {
			a[i] -= x;
		}
		k -= (x * 3);
		x = 1e18;
		vector<string>v;
		for (int i = 0; i<3; i++) {
			if (!a[i])continue;
			x = min(x, a[i]);
			v.push_back(solve1(i));
		}
		if (x * 2 >= k) {
			if(v.size()==1){
			  return v[0];
			}else{
			  return v[(k&1)==1?0:1];
			}
		}
		for (int i = 0; i<3; i++) {
			if (!a[i])continue;
			a[i] -= x;
		}
		for (int i = 0; i<3; i++) {
			if (a[i]) {
				return solve1(i);
			}
		}
	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, long long p0, long long p1, long long p2, long long p3, bool hasAnswer, string p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3;
	cout << "]" << endl;
	AlternateColors *obj;
	string answer;
	obj = new AlternateColors();
	clock_t startTime = clock();
	answer = obj->getColor(p0, p1, p2, p3);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p4 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p4;
	}
	if (!res) {
		cout << "DOESN'T MATCH!!!!" << endl;
	}
	else if (double(endTime - startTime) / CLOCKS_PER_SEC >= 2) {
		cout << "FAIL the timeout" << endl;
		res = false;
	}
	else if (hasAnswer) {
		cout << "Match :-)" << endl;
	}
	else {
		cout << "OK, but is it right?" << endl;
	}
	cout << "" << endl;
	return res;
}
int main() {
	bool all_right;
	all_right = true;

	long long p0;
	long long p1;
	long long p2;
	long long p3;
	string p4;

	{
		// ----- test 0 -----
		p0 = 29ll;
		p1 = 48ll;
		p2 = 24ll;
		p3 = 94ll;
		p4 = "GREEN";
		all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		p0 = 3ll;
		p1 = 4ll;
		p2 = 5ll;
		p3 = 4ll;
		p4 = "RED";
		all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		p0 = 7ll;
		p1 = 7ll;
		p2 = 1ll;
		p3 = 7ll;
		p4 = "GREEN";
		all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		p0 = 1000000000000ll;
		p1 = 1ll;
		p2 = 1ll;
		p3 = 1000000000002ll;
		p4 = "RED";
		all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		p0 = 653ll;
		p1 = 32ll;
		p2 = 1230ll;
		p3 = 556ll;
		p4 = "BLUE";
		all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
		// ------------------
	}

	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	}
	else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// END KAWIGIEDIT TESTING
//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!