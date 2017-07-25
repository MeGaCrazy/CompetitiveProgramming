/*
*    target : generate the  string with cnt1,cnt2,cnt3,cnt4;
*       sol : as u see u can make sequence of 47 74 only if diffeence is One :)
*             so from this obervation if c==d+1 so generate 47 sequence and just at the end put some 4 in front and some 7 in last
*              and make that for situation on d==c+1
*
*/
#include <bits/stdc++.h>
using namespace std;
string s;
int a, b, c, d, back = -1;

int main() {

	scanf("%d %d %d %d", &a, &b, &c, &d);
	if (abs(c - d)>1) {
		printf("-1");
		return 0;
	}
	
	if (c == d + 1) {
		while (c--) {
			s += "47";
			a--, b--;
		}
	}
	else if (d == c + 1) {
		while (d--) {
			s +="74";
			a--, b--;
		}
	}
	else if (c == d) {
		while (c--) {
			s +="47";
			a--, b--;
		}
		if (a > 0) {
			s = s + "4";
			a--;
		}
		else {
			s = "7" + s;
			b--;
 		}
	

	}


	if (a<0 || b<0) {
		printf("-1");
		return 0;
	}
	for (int i = s.size() - 1; i >= 1; i--) {
		if (s[i] == '7') { back = i; break; }
	}

	for (int i = 0; i<(int)s.size(); i++) {
		printf("%c", s[i]);
		if (a>0 && s[i] == '4') {
			while (a--) { printf("4"); }
		}
		if (i == back) {
			while (b--) { printf("7"); }
		}
	}
}