/*
     target : get the shortest path to make rotation to make the numbers return to it's original
     sol    : Using Trie and BFS every step make all rotation possible clockwise and counterclockwise
*/


#include <cstdio>
#include <cstring>
#include <cassert>
#include <queue>
using namespace std;
const int N = 362980;
char str[N][10] = { "123456789" };
int dis[N];
struct trie {
	trie* s[10];
	int index;
	trie() {
		memset(s, 0, sizeof(s));
		index = -1;
	}
	void insert(char *ss, int &k) {
		if (*ss == '\0') {
			if (index == -1)index = k++;
		}
		else {
			int cur = *ss - '0';
			if (s[cur] == 0) {
				s[cur] = new trie();
			}
			s[cur]->insert(ss + 1, k);
		}
		
	}
	int Distance(char *ss) {
		if (*ss == '\0') {
			return index;
		}
		else {
			int cur = *ss - '0';
			if (s[cur] == 0)return -1;
			s[cur]->Distance(ss + 1);
		}
	}
}*t;
int Rotate[8][4] = {
	{ 0,3,4,1 },{ 1,4,5,2 },{ 3,6,7,4 },{ 4,7,8,5 }
	,{ 0,1,4,3 },{ 1,2,5,4 },{ 3,4,7,6 },{ 4,5,8,7 }

};
void bfs() {
	char tmp[12] = { 0 };
	int k = 0;
	dis[0] = 0;
	queue<int>q;
	q.push(0);
	t->insert(str[0], k);
	int j;
	while (!q.empty()) {
		int a = q.front();
		q.pop();
		if (dis[a] >= 9)continue;
		for (int i = 0; i<8; i++) {
			strcpy(tmp, str[a]);
			char x = tmp[Rotate[i][0]];
			for (j = 1; j<4; j++) {
				tmp[Rotate[i][j - 1]] = tmp[Rotate[i][j]];
			}
			tmp[Rotate[i][j-1]] = x;
			int y = k;
			t->insert(tmp, k);
			if (y != k) { //oh wow it's new make new index for him  :) 
				dis[k] = dis[a] + 1;
				q.push(k);
				strcpy(str[k], tmp);
			}
		}
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	char input[15] = {};
	int cas = 1;
	t = new trie();
	bfs();

	while (scanf("%s", input), input[1]>'0') {
//		printf("%d. ", cas++);
		int k = input[0] - '0';
		int dis_index = t->Distance(&input[1]);
		if (dis_index == -1 || dis[dis_index] > k) printf("%d. -1\n", cas++);
		else printf("%d. %d\n", cas++, dis[dis_index]);
		}
}
