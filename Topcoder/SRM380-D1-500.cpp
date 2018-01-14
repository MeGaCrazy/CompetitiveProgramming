/**
*       Idea : just use binary search to check the maximum value they can play okey put if number in cards less than maximum number we got?
*              easy if the missing cards can be repalced with jokers
*
*
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


class CompilingDecksWithJokers {
public:
	int maxCompleteDecks(vector <int> cards, int jokers) {
		sort(cards.begin(), cards.end());
		int n = (int)cards.size();
		vector<long long>a;
		for (int i = 0; i < cards.size(); i++) {
			a.push_back(cards[i]);
		}
		long long l = 0, r =a[n - 1] + jokers + 2;
		while (l < r) {
			long long mid = (l + r) >> 1;
			long long need = 0;
			for (int i = 0; i<n; i++) {
				if (mid > cards[i])need += mid - a[i];
			}
			if (need <= mid && need <= jokers)l = mid + 1;
			else r = mid;
		}
		return (int)l - 1;

	}
};


// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector <int> p0, int p1, bool hasAnswer, int p2) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << p1;
	cout << "]" << endl;
	CompilingDecksWithJokers *obj;
	int answer;
	obj = new CompilingDecksWithJokers();
	clock_t startTime = clock();
	answer = obj->maxCompleteDecks(p0, p1);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p2 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p2;
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

	vector <int> p0;
	int p1;
	int p2;

	{
		// ----- test 0 -----
		int t0[] = { 10,15 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 3;
		p2 = 13;
		all_right = KawigiEdit_RunTest(0, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 1,2,3 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 4;
		p2 = 3;
		all_right = KawigiEdit_RunTest(1, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 1 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 5;
		p2 = 6;
		all_right = KawigiEdit_RunTest(2, p0, p1, true, p2) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 2,3,4,5,6 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = 4;
		p2 = 4;
		all_right = KawigiEdit_RunTest(3, p0, p1, true, p2) && all_right;
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
