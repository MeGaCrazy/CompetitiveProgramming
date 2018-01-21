/**
*   @Author : MeGaCrazy
*   @InitTime : Sun Jan 21 17:52:59 2018
*   @Idea :  First We will use dp with state [curplayer][MaskOfPlayer1][MaskOfPlayer2]
*            Mask will contains the sections he cover it sofar for each player
*            Well now for every player I have two choice number from 1..9 Only statisfy the condition below:
*	     1- if I take this section And Win
*            2- Or If I taken this section can't make him win in next move
*	     if there's no such element u can choose Guess What!! you lose :) 
*        
*  Happy Solving :)
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
const int N = 1500;
int dp[2][N][N];
int ans;

class Fifteen {
public:

	bool Best(int idx, int x, int mask1, int mask2) {
		vector<int> v1, v2;
		int a1[10] = { 0 };
		int a2[10] = { 0 };
		for (int i = 1; i <= 9; i++) {
			if ((mask1 & (1 << i))) {
				v1.push_back(i);
				a1[i] = 1;
			}
		}
		for (int i = 1; i <= 9; i++) {
			if ((mask2 & (1 << i))) {
				v2.push_back(i);
				a2[i] = 1;
			}

		}
		if (idx == 0) {
			a1[x] = 1;
			for (int i = 0; i < (int)v1.size(); i++) {
				for (int j = i + 1; j < (int)v1.size(); j++) {
					if (v1[i] + v1[j] + x == 15) {
						return 1;
					}
				}
			}
			for (int i = 0; i < (int)v2.size(); i++) {
				for (int j = i + 1; j < (int)v2.size(); j++) {
					int tmp = (15 - (v2[i] + v2[j]));
					if (tmp > 0 && a1[tmp] == 0 && a2[tmp] == 0) {
						return 0;
					}
				}
			}
			return 1;
		}
		else {
			a2[x] = 1;
			for (int i = 0; i < (int)v2.size(); i++) {
				for (int j = i + 1; j < (int)v2.size(); j++) {
					if (v2[i] + v2[j] + x == 15) {
						return 1;
					}
				}
			}
			//cout<<"X "<<x<<endl;
			for (int i = 0; i < (int)v1.size(); i++) {
				for (int j = i + 1; j < (int)v1.size(); j++) {
					int tmp = (15 - (v1[i] + v1[j]));
					if (tmp > 0 && a2[tmp] == 0 && a1[tmp] == 0) {
						return 0;
					}
				}
			}
			return 1;
		}
		return 0;
	}
	bool Win(int idx, int mask1, int mask2) {
		vector<int> v;

		if (idx == 0) {
			for (int i = 1; i <= 9; i++) {
				if ((mask1 & (1 << i))) {
					v.push_back(i);
				}
			}
			for (int i = 0; i < (int)v.size(); i++) {
				for (int j = i + 1; j < (int)v.size(); j++) {
					for (int k = j + 1; k < (int)v.size(); k++) {
						if (v[i] + v[j] + v[k] == 15) {
							return 1;
						}
					}
				}
			}
		}
		else {
			for (int i = 1; i <= 9; i++) {
				if ((mask2 & (1 << i))) {
					v.push_back(i);
				}
			}
			for (int i = 0; i < (int)v.size(); i++) {
				for (int j = i + 1; j < (int)v.size(); j++) {
					for (int k = j + 1; k < (int)v.size(); k++) {
						if (v[i] + v[j] + v[k] == 15) {
							return 1;
						}
					}
				}
			}

		}
		return 0;
	}
	bool Full(int mask1, int mask2) {
		int cnt = 0;
		for (int i = 1; i <= 9; i++) {
			if ((mask1 & (1 << i))) {
				cnt++;
			}
		}
		for (int i = 1; i <= 9; i++) {
			if ((mask2 & (1 << i))) {
				cnt++;
			}

		}
		return cnt == 9;
	}
	int solve(int idx, int mask1, int mask2) {
		if (Full(mask1, mask2)) {
			return 0;
		}
		int &ret = dp[idx][mask1][mask2];
		if (ret != -1) {
			return ret;
		}
		for (int i = 1; i <= 9; i++) {
			if ((mask1 & (1 << i)) == 0 && (mask2 & (1 << i)) == 0
				&& Best(idx, i, mask1, mask2) == 1) {
				if (idx == 0) {
					bool w = Win(idx, mask1 | (1 << i), mask2);
					if (w)
						return ret = 1;
					if (solve(1 - idx, mask1 | (1 << i), mask2) == 0)
						return ret = 1;
				}
				else {
					bool w = Win(idx, mask1, mask2 | (1 << i));
					if (w) {
						ans = i;
						return ret = 1;
					}
					if (solve(1 - idx, mask1, mask2 | (1 << i)) == 0) {
						ans = i;
						return ret = 1;
					}
				}
			}
		}
		return ret = 0;
	}
	string outcome(vector<int> moves) {
		int mask1 = 0, mask2 = 0;
		memset(dp, -1, sizeof(dp));
		ans = 1e9;
		for (int i = 0; i < (int)moves.size(); i++) {
			if ((i + 1) & 1) {
				mask1 |= (1 << moves[i]);
			}
			else {
				mask2 |= (1 << moves[i]);
			}
		}
		bool ret = solve(1, mask1, mask2);
		if (ret == 0)return "LOSE";
		//stringstream out;
		//out << "WIN " << ans;
		char str[50] = {};
		sprintf(str, "WIN %d", ans);
		return str;
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, vector<int> p0, bool hasAnswer,
	string p1) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}";
	cout << "]" << endl;
	Fifteen *obj;
	string answer;
	obj = new Fifteen();
	clock_t startTime = clock();
	answer = obj->outcome(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC
		<< " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << "\"" << p1 << "\"" << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << "\"" << answer << "\"" << endl;
	if (hasAnswer) {
		res = answer == p1;
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

	vector<int> p0;
	string p1;

	{
		// ----- test 0 -----
		int t0[] = { 1, 5, 2, 4, 9 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 3";
		all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 1 -----
		int t0[] = { 4, 8, 6, 5, 2 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "LOSE";
		all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 2 -----
		int t0[] = { 2, 4, 7, 6, 9, 8, 5 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 1";
		all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 3 -----
		int t0[] = { 9, 2, 1, 6, 3, 4, 8 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 5";
		all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 4 -----
		int t0[] = { 1 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "LOSE";
		all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
		// ------------------
	}

	{
		// ----- test 5 -----
		int t0[] = { 1, 5, 2, 4, 9 };
		p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
		p1 = "WIN 3";
		all_right = KawigiEdit_RunTest(5, p0, true, p1) && all_right;
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
