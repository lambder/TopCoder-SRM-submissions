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
#define	tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define	present(x, c)	((c).find(x) != (c).end())		//map & set//
#define	cpresent(x, c)	(find(all(c),x) != (c).end())	//vector & list//

#define forn(i, n)	for(int i = 0, loop_ends_here = (int)n; i < loop_ends_here; i++)
#define forab(i, a, b)	for(int i = a, loop_ends_here = (int) b; i <= loop_ends_here; i++)
#define rep(i, a, b)	for(int i = a, loop_ends_here = (int)b; i>=loop_ends_here; i--)

class RedAndGreen
{
public:
	int minPaints(string row)
	{
		int ret1 = 0, ret2 = 0;
		int len = row.length();

		forn(i, len-1) {
			if(row[i] == 'R')	continue;

			bool f = false;

			forab(j, i+1, len - 1)
				f |= row[j] == 'R';

			f && ++ret1;
		}

		rep(i, len-1, 1) {
			if(row[i] == 'G')	continue;

			bool f= false;

			rep(j, i-1, 0)
				f |= row[j] == 'G';
			f && ++ret2;
		}
		
		return min(ret1, ret2);
	}
};

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, string p0, bool hasAnswer, int p1) {
	cout << "Test " << testNum << ": [" << "\"" << p0 << "\"";
	cout << "]" << endl;
	RedAndGreen *obj;
	int answer;
	obj = new RedAndGreen();
	clock_t startTime = clock();
	answer = obj->minPaints(p0);
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
		res = answer == p1;
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
	
	string p0;
	int p1;
	
	{
	// ----- test 0 -----
	p0 = "RGRGR";
	p1 = 2;
	all_right = KawigiEdit_RunTest(0, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = "RRRGGGGG";
	p1 = 0;
	all_right = KawigiEdit_RunTest(1, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = "GGGGRRR";
	p1 = 3;
	all_right = KawigiEdit_RunTest(2, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = "RGRGRGRGRGRGRGRGR";
	p1 = 8;
	all_right = KawigiEdit_RunTest(3, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = "RRRGGGRGGGRGGRRRGGRRRGR";
	p1 = 9;
	all_right = KawigiEdit_RunTest(4, p0, true, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = "R";
	all_right = KawigiEdit_RunTest(5, p0, false, p1) && all_right;
	// ------------------
	}
	
	{
	// ----- test 6 -----
	p0 = "B";
	all_right = KawigiEdit_RunTest(6, p0, false, p1) && all_right;
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
// 
// You have several squares arranged in a single row. Each square is currently painted red or green. You can choose any of the squares and paint it over with either color. The goal is that, after painting, every red square is further to the left than any of the green squares. We want you to do it repainting the minimum possible number of squares.
// 
// Squares are numbered from left to right. You will be given the initial arrangement as a string row, such that character i is 'R' if square i is red or 'G' if square i is green. Return the minimum number of repaints needed to achieve the goal.
// 
// 
// DEFINITION
// Class:RedAndGreen
// Method:minPaints
// Parameters:string
// Returns:int
// Method signature:int minPaints(string row)
// 
// 
// CONSTRAINTS
// -row will contain between 1 and 50 characters, inclusive.
// -Each character of row will be either 'R' or 'G'.
// 
// 
// EXAMPLES
// 
// 0)
// "RGRGR"
// 
// Returns: 2
// 
// Paint the squares in the marked positions in the picture below with the opposite color. There are other ways with 2 total paints.
// 
// RGRGR
//  |  |
// RRRGG
// 
// 
// 1)
// "RRRGGGGG"
// 
// Returns: 0
// 
// There is no need to paint anything.
// 
// 2)
// "GGGGRRR"
// 
// Returns: 3
// 
// Paint all the red squares green.
// 
// 3)
// "RGRGRGRGRGRGRGRGR"
// 
// Returns: 8
// 
// 
// 
// 4)
// "RRRGGGRGGGRGGRRRGGRRRGR"
// 
// Returns: 9
// 
// 
// 
// END KAWIGIEDIT TESTING



//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
