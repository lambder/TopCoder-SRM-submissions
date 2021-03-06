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
#include <cassert>
#include <climits>
#include <cstring>
using namespace std;

typedef long long  int64;
typedef vector<int> vi;
typedef string ST;
typedef stringstream SS;
typedef vector< vector <int> > vvi;
typedef pair<int,int> ii;
typedef vector <string> vs;

#define Pf	printf
#define	Sf	scanf

#define	ep	1e-9
#define PI M_PI
#define E M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp	make_pair

#define	pb	push_back

#define	all(c)	(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int) b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i>=loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class ChessMetric
{
public:
	long long howMany(int size, vector <int> start, vector <int> end, int numMoves);
};

int sx, sy, ex, ey;
int N;
long long ret;
const int X[] = {1, 0, -1,  0,   1,  1, -1, -1,   2,  2, -2, -2,   1, -1, 1, -1};
const int Y[] = {0, 1,  0, -1,   1, -1,  1, -1,   1, -1,  1, -1,   2, 2, -2, -2};
//const int sz = 16;
int moves;

bool valid(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

int64 solve() {
	int64 dp[111][111] = {};
	int64 dp1[111][111] = {};

	dp[sx][sy] = 1ll;

	forab(m, 1, moves) {
		CL(dp1, 0);
		forn(x, N)	forn(y, N) 	forn(i, 16){
			int xx = x + X[i], yy = y + Y[i];
			if(!valid(xx, yy))	continue;
			dp1[xx][yy] += dp[x][y];
		}

		forn(x, N)	forn(y, N)
			dp[x][y] = dp1[x][y];

	}
	return dp[ex][ey];
}

long long ChessMetric::howMany (int size, vector <int> start, vector <int> end, int numMoves) 
{
	sx = start[0], sy = start[1];
	ex = end[0], ey = end[1];
	ret = 0ll;
	N = size;
	moves = numMoves;
	
	return solve();
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, vector <int> p1, vector <int> p2, int p3, bool hasAnswer, long long p4) {
	cout << "Test " << testNum << ": [" << p0 << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p2[i];
	}
	cout << "}" << "," << p3;
	cout << "]" << endl;
	ChessMetric *obj;
	long long answer;
	obj = new ChessMetric();
	clock_t startTime = clock();
	answer = obj->howMany(p0, p1, p2, p3);
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
	vector <int> p1;
	vector <int> p2;
	int p3;
	long long p4;
	
	{
	// ----- test 0 -----
	p0 = 3;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 1ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 3;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {1,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 1ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {2,2};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 1;
	p4 = 0ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 3;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,0};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 2;
	p4 = 5ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 100;
	int t1[] = {0,0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	int t2[] = {0,99};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 50;
	p4 = 243097320072600ll;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, true, p4) && all_right;
	// ------------------
	}
	
	if (all_right) {
		cout << "You're a stud (at least on the example cases)!" << endl;
	} else {
		cout << "Some of the test cases had errors." << endl;
	}
	return 0;
}
// PROBLEM STATEMENT
// Suppose you had an n by n chess board and a super piece called a kingknight.  Using only one move the kingknight denoted 'K' below can reach any of the spaces denoted 'X' or 'L' below:
//    .......
//    ..L.L..
//    .LXXXL.
//    ..XKX..
//    .LXXXL.
//    ..L.L..
//    .......
// 
// In other words, the kingknight can move either one space in any direction (vertical, horizontal or diagonally) or can make an 'L' shaped move.  An 'L' shaped move involves moving 2 spaces horizontally then 1 space vertically or 2 spaces vertically then 1 space horizontally.  In the drawing above, the 'L' shaped moves are marked with 'L's whereas the one space moves are marked with 'X's.  In addition, a kingknight may never jump off the board.
// 
// Given the size of the board, the start position of the kingknight and the end position of the kingknight, your method will return how many possible ways there are of getting from start to end in exactly numMoves moves.  start and finish are vector <int>s each containing 2 elements.  The first element will be the (0-based) row position and the second will be the (0-based) column position.  Rows and columns will increment down and to the right respectively.  The board itself will have rows and columns ranging from 0 to size-1 inclusive.  
// 
// Note, two ways of getting from start to end are distinct if their respective move sequences differ in any way.  In addition, you are allowed to use spaces on the board (including start and finish) repeatedly during a particular path from start to finish.  We will ensure that the total number of paths is less than or equal to 2^63-1 (the upper bound for a long long).
// 
// DEFINITION
// Class:ChessMetric
// Method:howMany
// Parameters:int, vector <int>, vector <int>, int
// Returns:long long
// Method signature:long long howMany(int size, vector <int> start, vector <int> end, int numMoves)
// 
// 
// NOTES
// -For C++ users: long long is a 64 bit datatype and is specific to the GCC compiler.
// 
// 
// CONSTRAINTS
// -size will be between 3 and 100 inclusive
// -start will contain exactly 2 elements
// -finish will contain exactly 2 elements
// -Each element of start and finish will be between 1 and size-1 inclusive
// -numMoves will be between 1 and 50 inclusive
// -The total number of paths will be at most 2^63-1.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// {0,0}
// {1,0}
// 1
// 
// Returns: 1
// 
// Only 1 way to get to an adjacent square in 1 move
// 
// 1)
// 3
// {0,0}
// {1,2}
// 1
// 
// Returns: 1
// 
// A single L-shaped move is the only way
// 
// 2)
// 3
// {0,0}
// {2,2}
// 1
// 
// Returns: 0
// 
// Too far for a single move
// 
// 3)
// 3
// {0,0}
// {0,0}
// 2
// 
// Returns: 5
// 
// Must count all the ways of leaving and then returning to the corner
// 
// 4)
// 100
// {0,0}
// {0,99}
// 50
// 
// Returns: 243097320072600
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
