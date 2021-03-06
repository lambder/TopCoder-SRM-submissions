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

class AvoidRoads
{
public:
	long long numWays(int width, int height, vector <string> bad);
};

int64 dp[505][505];
vector <pair <ii, ii > > bad;

bool isBad(ii a, ii b) {
	tr(it, bad) 
		if(it->first == a && it->second == b)
			return true;
		else if(it->second == a && it->first == b)
			return true;
	
	return false;
}

int64 calcdist(int x, int y) {
	int64 &ret = dp[x][y];
	if(ret > -1)
		return ret;
	ret = 0;

	if(x > 0 && !isBad( mp(x, y), mp(x-1, y) ) )
		ret += calcdist(x-1, y);
	if(y > 0 && !isBad( mp(x, y), mp(x, y-1) ) )
		ret += calcdist(x, y-1);
	return ret;
}

long long AvoidRoads::numWays (int width, int height, vector <string> _bad) 
{
	CL(dp, -1);
	bad.clear();
	tr(it, _bad) {
		SS ss(*it);
		int a, b, c, d;
		ss >> a >> b >> c >> d;
		bad.pb( mp( mp(a, b), mp(c, d) ) );
	}

	dp[0][0] = 1;
	return calcdist(width, height);
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, vector <string> p2, bool hasAnswer, long long p3) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << "{";
	for (int i = 0; int(p2.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p2[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	AvoidRoads *obj;
	long long answer;
	obj = new AvoidRoads();
	clock_t startTime = clock();
	answer = obj->numWays(p0, p1, p2);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p3 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p3;
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
	int p1;
	vector <string> p2;
	long long p3;
	
	{
	// ----- test 0 -----
	p0 = 6;
	p1 = 6;
	string t2[] = {"0 0 0 1","6 6 5 6"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 252ll;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 1;
	p1 = 1;
	p2.clear() /*{}*/;
	p3 = 2ll;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 35;
	p1 = 31;
	p2.clear() /*{}*/;
	p3 = 6406484391866534976ll;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, true, p3) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 2;
	p1 = 2;
	string t2[] = {"0 0 1 0","1 2 2 2","1 1 2 1"};
			p2.assign(t2, t2 + sizeof(t2) / sizeof(t2[0]));
	p3 = 0ll;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, true, p3) && all_right;
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
// Problem contains images.  Plugin users can view them in the applet.
// In the city, roads are arranged in a grid pattern.  Each point on the grid represents a corner where two blocks meet.  The points are connected by line segments which represent the various street blocks.  Using the cartesian coordinate system, we can assign a pair of integers to each corner as shown below. 
// 
// 
// 
// You are standing at the corner with coordinates 0,0.  Your destination is at corner width,height.  You will return the number of distinct paths that lead to your destination.  Each path must use exactly width+height blocks.  In addition, the city has declared certain street blocks untraversable.  These blocks may not be a part of any path.  You will be given a vector <string> bad describing which blocks are bad.  If (quotes for clarity) "a b c d" is an element of bad, it means the block from corner a,b to corner c,d is untraversable.  For example, let's say 
// width  = 6
// length = 6
// bad = {"0 0 0 1","6 6 5 6"}
// The picture below shows the grid, with untraversable blocks darkened in black.  A sample path has been highlighted in red.
// 
// 
// 
// 
// DEFINITION
// Class:AvoidRoads
// Method:numWays
// Parameters:int, int, vector <string>
// Returns:long long
// Method signature:long long numWays(int width, int height, vector <string> bad)
// 
// 
// CONSTRAINTS
// -width will be between 1 and 100 inclusive.
// -height will be between 1 and 100 inclusive.
// -bad will contain between 0 and 50 elements inclusive.
// -Each element of bad will contain between 7 and 14 characters inclusive.
// -Each element of the bad will be in the format "a b c d" where,  a,b,c,d are integers with no extra leading zeros, a and c are between 0 and width inclusive, b and d are between 0 and height inclusive,and  a,b is one block away from c,d.
// -The return value will be between 0 and 2^63-1 inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// 6
// 6
// {"0 0 0 1","6 6 5 6"}
// 
// Returns: 252
// 
// Example from above.
// 
// 1)
// 1
// 1
// {}
// 
// Returns: 2
// 
// Four blocks aranged in a square.  Only 2 paths allowed.
// 
// 2)
// 35
// 31
// {}
// 
// Returns: 6406484391866534976
// 
// Big number.
// 
// 3)
// 2
// 2
// {"0 0 1 0", "1 2 2 2", "1 1 2 1"}
// 
// Returns: 0
// 
// END KAWIGIEDIT TESTING


//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
