
#include<iostream>
#include<string>
#include<queue>

using namespace std;

const char EAST = 'E';
const char SOUTH = 'S';
const int MAX_GRID = 50000+2;
struct pos {
	int nr, nc;
	pos() :nr(0), nc(0) {}
};

pos PATH[2*MAX_GRID];
void RESET_GRID(int N) {
	for (int i = 0; i < 2*N; i++) {
		//for (int j = 0; j < N; j++) {
			PATH[i].nc = PATH[i].nr= 0;
		//}
	}
}

struct BFSele {
	int r, c; string s;
};

bool CheckFromTo(int oldr, int oldc, int newr, int newc, int N) {
	if (oldr == newr) {//East move
		int i = 0;
		for (; i < 2 * N; i++) {
			if (PATH[i].nc == newc) {
				break;
			}
		}
		while (PATH[i].nc == newc && i < 2 * N) {
			if (PATH[i].nr == newr) {
				if ((PATH[i - 1].nr == oldr) && (PATH[i - 1].nc == oldc))return true;
			}
			i++;
		}
	}
	else {//South Move
		int i = 0;
		for (; i < 2 * N; i++) {
			if (PATH[i].nr == newr) {
				break;
			}
		}
		while (PATH[i].nr == newr && i < 2 * N) {
			if (PATH[i].nc == newc) {
				if ((PATH[i - 1].nr == oldr) && (PATH[i - 1].nc == oldc))return true;
			}
			i++;
		}
	}
	return false;
}

void Solve(int N, string A, string& B) {
	string::iterator it = A.begin();
	int counter=1;
	while (it < A.end()) {
		if (*it == EAST) {
			PATH[counter].nc = PATH[counter-1].nc + 1;
			PATH[counter].nr = PATH[counter-1].nr;
		}
		else { //char is S
			PATH[counter].nc = PATH[counter-1].nc;
			PATH[counter].nr = PATH[counter-1].nr+1;
		}
		++it; counter++;
	}
	BFSele E,E2; E.r = 0; E.c = 0;
	queue<BFSele> OQ;
	OQ.push(E);
	while (!OQ.empty()) {
		E = OQ.front(); OQ.pop();
		if (E.r == N - 1 && E.c == N - 1) {
			B = E.s; return;
		}
		E2 = E;
		//Process East
		if (!CheckFromTo(E.r,E.c,E.r,E.c+1,N) && (E.c + 1 < N)) {
			E.c = E.c + 1; E.s = E.s + EAST;
			OQ.push(E);
		}
		//Process South
		if (!CheckFromTo(E2.r, E2.c, E2.r+1, E2.c, N) && (E2.r + 1 < N)) {
			E2.r = E2.r + 1; E2.s = E2.s + SOUTH;
			OQ.push(E2);
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int i = 0; i<T; i++) {
		int N; string A; string B;
		cin >> N >> A;
		RESET_GRID(N);
		Solve(N, A, B);
		cout << "Case #" << i + 1 << ": " <<B<< endl;
	}
	return 0;
}
