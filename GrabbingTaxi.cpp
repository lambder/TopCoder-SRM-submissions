#include <iostream>
#include <ctime>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cassert>
#include <utility>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iterator>
#include <fstream>
using namespace std;

typedef long long 		int64;
typedef vector<int> 		vi;
typedef string 			ST;
typedef stringstream 		SS;
typedef vector< vector<int> > 	vvi;
typedef pair<int,int> 		ii;
typedef vector<string> 		vs;
/*
#if __cplusplus > 199711L	// for g++0x, value of __cplusplus must be greater thana 199711L.
	#define tr(i, c)	for(auto i = begin(c); i != end(c); i++)
#else
	#define tr(i, c)	for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#endif
*/
#define endl		("\n")
#define tr(i, c)	for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define PI		M_PI
#define E 		M_E
#define	eps		1e-9

#define	Sf		scanf
#define	Pf		printf

#define forn(i, n)	for(int i = 0, lets_stop_here = (int)n; i <  lets_stop_here; i++)
#define forab(i, a, b)	for(int i = a, lets_stop_here = (int)b; i <= lets_stop_here; i++)
#define rep(i, a, b)	for(int i = a, lets_stop_here = (int)b; i >= lets_stop_here; i--)

#define	all(c)		(c).begin(), (c).end()
#define	cl(a, b)	memset(a, b, sizeof(a))
#define mp		make_pair
#define pb		push_back

#define	present(x, c)	((c).find(x) != (c).end())	//map & set//
#define	cpresent(x, c)	(find( (c).begin(), (c).end(), x) != (c).end())	//vector & list//

#define read(n)		scanf("%d", &n)
#define write(n)	printf("%d ", n)
#define writeln(n)	printf("%d\n", n)

#if (0)
	#define debug 
#else 
	#define debug(x)	cout << #x << " = " << x << "\n"
#endif

class GrabbingTaxi
{
public:
	int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime);
};

int GrabbingTaxi::minTime (vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime) 
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
bool KawigiEdit_RunTest(int testNum, vector <int> p0, vector <int> p1, int p2, int p3, int p4, int p5, bool hasAnswer, int p6) {
	cout << "Test " << testNum << ": [" << "{";
	for (int i = 0; int(p0.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p0[i];
	}
	cout << "}" << "," << "{";
	for (int i = 0; int(p1.size()) > i; ++i) {
		if (i > 0) {
			cout << ",";
		}
		cout << p1[i];
	}
	cout << "}" << "," << p2 << "," << p3 << "," << p4 << "," << p5;
	cout << "]" << endl;
	GrabbingTaxi *obj;
	int answer;
	obj = new GrabbingTaxi();
	clock_t startTime = clock();
	answer = obj->minTime(p0, p1, p2, p3, p4, p5);
	clock_t endTime = clock();
	delete obj;
	bool res;
	res = true;
	cout << "Time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " seconds" << endl;
	if (hasAnswer) {
		cout << "Desired answer:" << endl;
		cout << "\t" << p6 << endl;
	}
	cout << "Your answer:" << endl;
	cout << "\t" << answer << endl;
	if (hasAnswer) {
		res = answer == p6;
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
	
	vector <int> p0;
	vector <int> p1;
	int p2;
	int p3;
	int p4;
	int p5;
	int p6;
	
	{
	// ----- test 0 -----
	p0.clear() /*{}*/;
	p1.clear() /*{}*/;
	p2 = 3;
	p3 = 2;
	p4 = 10;
	p5 = 2;
	p6 = 50;
	all_right = KawigiEdit_RunTest(0, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 1 -----
	int t0[] = {-2,-2};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0,-2};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -4;
	p3 = -2;
	p4 = 15;
	p5 = 3;
	p6 = 42;
	all_right = KawigiEdit_RunTest(1, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 2 -----
	int t0[] = {3};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {0};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 5;
	p3 = 0;
	p4 = 10;
	p5 = 20;
	p6 = 50;
	all_right = KawigiEdit_RunTest(2, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 3 -----
	int t0[] = {34,-12,1,0,21,-43,-98,11,86,-31};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {11,5,-68,69,-78,-49,-36,-2,1,70};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = -97;
	p3 = -39;
	p4 = 47;
	p5 = 13;
	p6 = 2476;
	all_right = KawigiEdit_RunTest(3, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
	// ------------------
	}
	
	{
	// ----- test 4 -----
	int t0[] = {82,-60,57,98,30,-67,84,-42,-100,62};
			p0.assign(t0, t0 + sizeof(t0) / sizeof(t0[0]));
	int t1[] = {-7,90,53,-56,-15,-87,22,-3,-61,-30};
			p1.assign(t1, t1 + sizeof(t1) / sizeof(t1[0]));
	p2 = 21;
	p3 = 15;
	p4 = 53;
	p5 = 2;
	p6 = 1908;
	all_right = KawigiEdit_RunTest(4, p0, p1, p2, p3, p4, p5, true, p6) && all_right;
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
// You are walking in the city on a holiday. Suddenly, you are told to go to your office as soon as possible by your boss via cell phone. The city is infinite in size, with vertical streets located at every integer X value and horizontal streets located at every Y value. You are currently located at (0, 0) and your office is located at (gX, gY). There are some taxi stands in the city and their locations are (tXs[i], tYs[i]). You can either go to the office by foot or go to some taxi stand, get a taxi there and go to the office by taxi. It takes walkTime seconds to go along the street to proceed to a horizontally or vertically adjacent intersection by foot and it takes taxiTime seconds by a taxi.
// 
// 
// Return the least amount of time that it will take you to go to your office.
// 
// 
// DEFINITION
// Class:GrabbingTaxi
// Method:minTime
// Parameters:vector <int>, vector <int>, int, int, int, int
// Returns:int
// Method signature:int minTime(vector <int> tXs, vector <int> tYs, int gX, int gY, int walkTime, int taxiTime)
// 
// 
// CONSTRAINTS
// -tXs will contain between 0 and 50 elements, inclusive.
// -tXs and tYs will contain the same number of elements.
// -Each element of tXs and tYs will be between -10000 and 10000, inclusive.
// -gX and gY will be between -10000 and 10000, inclusive.
// -walkTime and taxiTime will be between 1 and 1000, inclusive.
// 
// 
// EXAMPLES
// 
// 0)
// {}
// {}
// 3
// 2
// 10
// 2
// 
// Returns: 50
// 
// There are no taxi stands. You have to walk to the goal.
// 
// 1)
// {-2, -2}
// {0, -2}
// -4
// -2
// 15
// 3
// 
// Returns: 42
// 
// First, you walk to (-2, 0) and get a taxi. Then you go to the goal by it.
// 
// 2)
// {3}
// {0}
// 5
// 0
// 10
// 20
// 
// Returns: 50
// 
// taxiTime may be larger than walkTime.
// 
// 3)
// {34, -12, 1, 0, 21, -43, -98, 11, 86, -31}
// {11, 5, -68, 69, -78, -49, -36, -2, 1, 70}
// -97
// -39
// 47
// 13
// 
// Returns: 2476
// 
// 
// 
// 4)
// {82, -60, 57, 98, 30, -67, 84, -42, -100, 62}
// {-7, 90, 53, -56, -15, -87, 22, -3, -61, -30}
// 21
// 15
// 53
// 2
// 
// Returns: 1908
// 
// 
// 
// END KAWIGIEDIT TESTING

//Powered by KawigiEdit 2.1.8 (beta) modified by pivanof!
