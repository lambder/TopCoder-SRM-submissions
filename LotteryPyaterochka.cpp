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

#define endl 		("\n")
#define DEBUG(x)	cout << #x << " = " << x << "\n"
#define Pf		printf
#define	Sf		scanf

#define	ep		1e-9
#define PI		M_PI
#define E 		M_E

#define	CL(a, b)	memset(a, b, sizeof(a))
#define	mp		make_pair
#define	pb		push_back

#define	all(c)		(c).begin(), (c).end()
#define	tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())		//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here ; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int)b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i >= loop_ends_here; i--)

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

class LotteryPyaterochka
{
public:
	double chanceToWin(int N);
};

double LotteryPyaterochka::chanceToWin (int N) 
{
	return (long double)24.0 * (long double)(125.0 * (N-1)*(N-1) + 1) / (long double)((5.0*N-1) * (5.0*N-2) * (5.0*N-3) * (5.0*N-4) );
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, bool hasAnswer, double p1) {
	cout << "Test " << testNum << ": [" << p0;
	cout << "]" << endl;
	LotteryPyaterochka *obj;
	double answer;
	obj = new LotteryPyaterochka();
	clock_t startTime = clock();
	answer = obj->chanceToWin(p0);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p1 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == answer && fabs(p1 - answer) <= 1e-9 * max(1.0, fabs(p1));
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
	double p1;
	
	{
	// ----- test 0 -----
	p0 = 1;
	p1 = 1.0;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 2;
	p1 = 1.0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 3;
	p1 = 0.5004995004995004;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 6;
	p1 = 0.13161551092585574;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
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
// Alice likes lotteries.  Her favorite lottery is Pyaterochka, which is very popular in Belarus.  Each ticket in this lottery is a rectangular grid with N rows and 5 columns, where each cell contains an integer between 1 and 5*N, inclusive.  All integers within a single ticket are distinct.
// 
// 
// After the tickets are distributed, the lottery organizers randomly choose 5 distinct integers, each between 1 and 5*N, inclusive.  Each possible subset of 5 integers has the same probability of being chosen.  These integers are called the winning numbers.  A ticket is considered a winner if and only if it has a row which contains at least 3 winning numbers.
// 
// 
// Alice will buy a single ticket.  Each possible ticket has the same probability of being sold.  Return the probability that she will buy a winning ticket.
// 
// DEFINITION
// Class:LotteryPyaterochka
// Method:chanceToWin
// Parameters:int
// Returns:double
// Method signature:double chanceToWin(int N)
// 
// 
// NOTES
// -Your return value must have an absolute or relative error less than 1e-9.
// 
// 
// CONSTRAINTS
// -N will be between 1 and 100, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 1
// 
// Returns: 1.0
// 
// Any ticket contains just one line with some permutation of numbers 1, 2, 3, 4, 5. Ony one set of winning numbers is possible - {1, 2, 3, 4, 5}. So the only line of any ticket contains all 5 winning numbers, and therefore each ticket is a winner.
// 
// 1)
// 2
// 
// Returns: 1.0
// 
// For any set of winning numbers chosen, there's exactly one line in any ticket that contains at least 3 winning numbers.
// 
// 2)
// 3
// 
// Returns: 0.5004995004995004
// 
// 3)
// 6
// 
// Returns: 0.13161551092585574
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
