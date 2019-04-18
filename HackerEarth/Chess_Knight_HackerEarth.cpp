
// https://www.hackerearth.com/practice/basic-programming/recursion/recursion-and-backtracking/practice-problems/algorithm/a-tryst-with-chess/



// Sample code to perform I/O:

#include <iostream>

using namespace std;

const int MAX_R = 11;
const int MAX_C = 11;

bool CHESS[MAX_R][MAX_C];

void PrintBoard() {
	for (int i = 0; i < MAX_R; i++) {
		cout << endl;
		for (int j = 0; j < MAX_C; j++) {
			cout << (CHESS[i][j] ? 'V':'N') <<" ";
		}
	}
	cout << endl;
}

struct pos {
	int r, c;
	pos() :r(0), c(0) {}
	pos(int rr, int cc) : r(rr), c(cc) {}
	bool valid() {
		return (r>0 && r<11 && c>0 && c<11);
	}
};

int GetMoves(pos from, int moves, int& npos) {

	if (!from.valid() || moves<=0) return npos;

	/*if (!CHESS[from.r][from.c]) {
		CHESS[from.r][from.c] = true;
		npos++;
		PrintBoard();
	}

	if (moves <= 0) return npos;*/

	//check top
	if (!CHESS[from.r - 2][from.c + 1]) {
		CHESS[from.r - 2][from.c + 1] = true;
		npos++;
		GetMoves(pos(from.r - 2, from.c + 1), moves - 1, npos);
	}
	if (!CHESS[from.r - 2][from.c - 1]) {
		CHESS[from.r - 2][from.c - 1] = true;
		npos++;
		GetMoves(pos(from.r - 2, from.c - 1), moves - 1, npos);
	}

	//check bottom
	if (!CHESS[from.r + 2][from.c + 1]) {
		CHESS[from.r + 2][from.c + 1] = true;
		npos++;
		GetMoves(pos(from.r + 2, from.c + 1), moves - 1, npos);
	}
	if (!CHESS[from.r + 2][from.c - 1]) {
		CHESS[from.r + 2][from.c - 1] = true;
		npos++;
		GetMoves(pos(from.r + 2, from.c - 1), moves - 1, npos);
	}

	//check left
	if (!CHESS[from.r - 1][from.c -2]) {
		CHESS[from.r - 1][from.c -2] = true;
		npos++;
		GetMoves(pos(from.r - 1, from.c - 2), moves - 1, npos);
	}
	if (!CHESS[from.r + 1][from.c - 2]) {
		CHESS[from.r + 1][from.c - 2] = true;
		npos++;
		GetMoves(pos(from.r + 1, from.c - 2), moves - 1, npos);
	}

	//check right
	if (!CHESS[from.r - 1][from.c + 2]) {
		CHESS[from.r - 1][from.c + 2] = true;
		npos++;
		GetMoves(pos(from.r - 1, from.c + 2), moves - 1, npos);
	}
	if (!CHESS[from.r + 1][from.c + 2]) {
		CHESS[from.r + 1][from.c + 2] = true;
		npos++;
		GetMoves(pos(from.r + 1, from.c + 2), moves - 1, npos);
	}

	return npos;
}


int main() {
	for (int r = 1; r<MAX_R; r++) {
		for (int c = 1; c<MAX_C; c++) {
			CHESS[r][c] = false;
		}
	}
	int r, c, moves;
	cin >> r >> c >> moves;										// Reading input from STDIN
	CHESS[r][c] = true;
	int n = 0;
	cout << GetMoves(pos(r, c), moves,n) << endl;		// Writing output to STDOUT
	return 0;
}

// Write your code here
