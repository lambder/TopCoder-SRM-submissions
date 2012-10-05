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

class ThreeTeleports
{
public:
	int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports);
};


int ThreeTeleports::shortestDistance (int xMe, int yMe, int xHome, int yHome, vector <string> teleports) 
{
	int ret;
	
	return ret;
}

// BEGIN KAWIGIEDIT TESTING
// Generated by KawigiEdit 2.1.8 (beta) modified by pivanof
#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool KawigiEdit_RunTest(int testNum, int p0, int p1, int p2, int p3, vector <string> p4, bool hasAnswer, int p5) {
	cout << "Test " << testNum << ": [" << p0 << "," << p1 << "," << p2 << "," << p3 << "," << "{";
	for (int i = 0; int(p4.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << "\"" << p4[i] << "\"";
	}
	cout << "}";
	cout << "]" << endl;
	ThreeTeleports *obj;
	int answer;
	obj = new ThreeTeleports();
	clock_t startTime = clock();
	answer = obj->shortestDistance(p0, p1, p2, p3, p4);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p5 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p5;
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
	int p2;
	int p3;
	vector <string> p4;
	int p5;
	
	{
	// ----- test 0 -----
	p0 = 3;
	p1 = 3;
	p2 = 4;
	p3 = 5;
	string t4[] = {"1000 1001 1000 1002","1000 1003 1000 1004","1000 1005 1000 1006"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 3;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	p0 = 0;
	p1 = 0;
	p2 = 20;
	p3 = 20;
	string t4[] = {"1 1 18 20","1000 1003 1000 1004","1000 1005 1000 1006"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 14;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	p0 = 0;
	p1 = 0;
	p2 = 20;
	p3 = 20;
	string t4[] = {"1000 1003 1000 1004","18 20 1 1","1000 1005 1000 1006"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 14;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	p0 = 10;
	p1 = 10;
	p2 = 10000;
	p3 = 20000;
	string t4[] = {"1000 1003 1000 1004","3 3 10004 20002","1000 1005 1000 1006"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 30;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	p0 = 3;
	p1 = 7;
	p2 = 10000;
	p3 = 30000;
	string t4[] = {"3 10 5200 4900","12212 8699 9999 30011","12200 8701 5203 4845"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 117;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, true, p5) && all_right;
	// ------------------
	}
	
	{
	// ----- test 5 -----
	p0 = 0;
	p1 = 0;
	p2 = 1000000000;
	p3 = 1000000000;
	string t4[] = {"0 1 0 999999999","1 1000000000 999999999 0","1000000000 1 1000000000 999999999"};
			p4.assign(t4, t4 + sizeof(t4) / sizeof(t4[0]));
	p5 = 36;
	all_right = KawigiEdit_RunTest(5, p0, p1, p2, p3, p4, true, p5) && all_right;
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
// You are a frog. You live on an infinite lattice of grid points. For each pair of integers x, y there is a grid point with coordinates (x,y). At this moment, you sit on the grid point (xMe,yMe). You want to get home: to the grid point (xHome,yHome).
// There are two ways in which you can travel. Your first option is jumping: if you are at (x,y), you can jump to one of the four neighboring grid points: (x+1,y), (x-1,y), (x,y+1), or (x,y-1). Each jump takes one second.
// Your second option is using a teleport. There are three teleports in the entire world. Each of them connects two different grid points. If you are at one of the endpoints, you may activate the teleport and travel to its other endpoint. Traveling by teleport takes 10 seconds.
// You are given ints xMe, yMe, xHome, yHome, and a vector <string> teleports that describes the three teleports. Each element of teleports will be a string containing four integers x1, y1, x2, and y2, separated by single spaces. These integers describe a teleport with endpoints at (x1,y1) and (x2,y2).
// Your method must return the shortest time in which you can reach your home.
// 
// DEFINITION
// Class:ThreeTeleports
// Method:shortestDistance
// Parameters:int, int, int, int, vector <string>
// Returns:int
// Method signature:int shortestDistance(int xMe, int yMe, int xHome, int yHome, vector <string> teleports)
// 
// 
// NOTES
// -Traveling by a teleport is not mandatory. You may pass through its endpoint and decide not to use it.
// 
// 
// CONSTRAINTS
// -xMe, yMe, xHome, and yHome will all be between 0 and 1,000,000,000, inclusive.
// -teleports will have exactly three elements.
// -Each element of teleports will have the following format: "x1 y1 x2 y2" (quotes for clarity), where x1, y1, x2, and y2 are integers between 0 and 1,000,000,000, inclusive. The integers x1, y1, x2, and y2 will not contain unnecessary leading zeroes.
// -All eight points (your location, the location of your home, and the six teleport endpoints) will be pairwise distinct.
// 
// 
// EXAMPLES
// 
// 0)
// 3
// 3
// 4
// 5
// {"1000 1001 1000 1002", "1000 1003 1000 1004", "1000 1005 1000 1006"}
// 
// Returns: 3
// 
// The frog must make at least 3 leaps. For example, from (3,3) to (3,4), then to (3,5), and finally to (4,5). The teleports are all too far away to be useful.
// 
// 1)
// 0
// 0
// 20
// 20
// {"1 1 18 20", "1000 1003 1000 1004", "1000 1005 1000 1006"}
// 
// Returns: 14
// 
// The journey can be done in 40 jumps = 40 seconds, but there is a better solution: Make 2 jumps to get from (0,0) to (1,1), use the teleport to get to (18,20), and make 2 jumps to get to (20,20). This solution takes (2+10+2) = 14 seconds.
// 
// 2)
// 0
// 0
// 20
// 20
// {"1000 1003 1000 1004", "18 20 1 1", "1000 1005 1000 1006"}
// 
// Returns: 14
// 
// The teleports may be used in either direction, and in any order.
// 
// 3)
// 10
// 10
// 10000
// 20000
// {"1000 1003 1000 1004", "3 3 10004 20002", "1000 1005 1000 1006"}
// 
// Returns: 30
// 
// 
// 
// 4)
// 3
// 7
// 10000
// 30000
// {"3 10 5200 4900", "12212 8699 9999 30011", "12200 8701 5203 4845"}
// 
// Returns: 117
// 
// Sometimes the best solution requires us to use more than one teleport. In this case, the optimal solution looks as follows:
// 
// Using jumps, travel to (3,10).
// Use the first teleport.
// Using jumps, travel from (5200,4900) to (5203,4845).
// Use the third teleport.
// Using jumps, travel from (12200,8701) to (12212,8699).
// Use the second teleport.
// Using jumps, travel from (9999,30011) to (10000,30000).
// 
// 
// 
// 5)
// 0
// 0
// 1000000000
// 1000000000
// {"0 1 0 999999999", "1 1000000000 999999999 0", "1000000000 1 1000000000 999999999"}
// 
// Returns: 36
// 
// Watch out for overflows. The correct return value will always fit into a int, but some other paths may be very long.
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
